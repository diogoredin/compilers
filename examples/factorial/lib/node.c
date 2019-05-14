/* $Id: node.c,v 1.1 2004/07/23 02:38:19 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "node.h"
int yyerror(char*);
extern int yylineno;

Node *newNode(NodeType t, int attrib, int nops) {
    Node *p;
    size_t size;
    int i;

    /* allocate node */
    size = sizeof(Node) + (t == nodeOpr ? nops * sizeof(Node*) : 0);
    if ((p = malloc(size)) == NULL) {
	yyerror("out of memory");
	exit(2);
    }

    /* copy information */
    p->type = t;
    p->attrib = attrib;
    p->line = yylineno;
    p->user = 0;
    p->state = 0;
    p->info = -1;
    p->value.sub.num = nops;
    if (nops > 0) {
	for (i = 0; i < nops; i++)
	    p->value.sub.n[i] = 0;		/* ensure NULL pointers */
    }

    return p;
}

Node *nilNode(int attrib) {
    return newNode(nodeNil, attrib, 0);
}
Node *uniNode(int attrib, Node *n1) {
  return subNode(attrib, 1, n1);
}
Node *binNode(int attrib, Node *n1, Node *n2) {
  return subNode(attrib, 2, n1, n2);
}
Node *triNode(int attrib, Node *n1, Node *n2, Node *n3) {
  return subNode(attrib, 3, n1, n2, n3);
}

Node *intNode(int attrib, regint i) {
    Node *p = newNode(nodeInt, attrib, 0);
    if (p != NULL) p->value.i = i;
    return p;
}

Node *realNode(int attrib, double d) {
    Node *p = newNode(nodeReal, attrib, 0);
    if (p != NULL) p->value.r = d;
    return p;
}

/*
Node *dataNode(int attrib, int size, void *user) {
    Node *p = newNode(nodeData, attrib, 0);
    if (p != NULL) {
      p->value.d.size = size;
      p->value.d.data = user;
    }
    return p;
}
*/

Node *strNode(int attrib, char *s) {
    Node *p = newNode(nodeStr, attrib, 0);
    if (p != NULL) p->value.s = s;
    return p;
}

Node *subNode(int oper, int nops, ...) {
    va_list ap;
    Node *p = newNode(nodeOpr, oper, nops);
    int i;

    if (p == NULL) return 0;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
	p->value.sub.n[i] = va_arg(ap, Node*);
    va_end(ap);
    return p;
}

Node *seqNode(int oper, int nops, ...) {
    va_list ap;
    Node *p, *q;
    int i;

    q = p = newNode(nodeOpr, oper, nops < 3 ? nops : 2);
    if (p == NULL) return 0;
    va_start(ap, nops);
    for (i = 0; i < nops; i++) {
	p->value.sub.n[0] = va_arg(ap, Node*);
	if (nops - i < 3) {
	    p->value.sub.n[1] = va_arg(ap, Node*);
	    break;
	} else {
	    p->value.sub.n[1] = newNode(nodeOpr, oper, nops - i < 3 ? nops - i : 2);
	    if (p->value.sub.n[1] == NULL) {
	        freeNode(q);
		q = 0;
		break;
	    }
	}
	p = p->value.sub.n[1];
    }
    va_end(ap);
    return q;
}

Node *addNode(Node *base, Node *node, unsigned pos) {
    Node *p;
    size_t size;

    if (base == 0 || base->type != nodeOpr) return 0;
    size = sizeof(Node) + (base->value.sub.num + 1) * sizeof(Node*);
    if ((p = realloc(base, size)) == NULL) {
        yyerror("out of memory");
        exit(2);
    }
    if (pos < 0 || pos > p->value.sub.num)
    	pos = p->value.sub.num; /* do not overflow */
    if (pos < p->value.sub.num)
      memmove(&p->value.sub.n[pos+1], &p->value.sub.n[pos],
	      (p->value.sub.num-pos)*sizeof(Node*));
    p->value.sub.n[pos] = node;
    p->value.sub.num++;
    return p;
}

Node *removeNode(Node *base, unsigned pos) {
    Node *p;

    if (base == 0 || base->type != nodeOpr) return 0;
    if (pos >= base->value.sub.num) return 0;

    base->value.sub.num--;
    p = base->value.sub.n[pos];
    memmove(&base->value.sub.n[pos], &base->value.sub.n[pos+1],
	      (base->value.sub.num-pos)*sizeof(Node*));
    return p;
}

int userNode(Node *p, int user) { //o parametro user era void*
    if (p == 0) return 0;
    if (user == 0) return p->user;
    return p->user = user;
}

void freeNode(Node *p) {
    int i;

    if (p == 0) return;
    if (p->type == nodeOpr) {
	for (i = 0; i < p->value.sub.num; i++)
	    freeNode(p->value.sub.n[i]);
    }
    free (p);
}

static int print(Node *p, FILE *fp, char *tab[], int lev) {
    int i, cnt = 0;
    
    if(p != NULL)
    fprintf(fp," USER: %d", p->user);
    
    if (p == 0) return cnt;
    cnt++;
    if (p->type == nodeOpr) fprintf(fp,"\n%*s(", 2*lev, " ");
    if (tab != 0)
      fprintf(fp," %s:", tab[p->attrib]);
    else
      fprintf(fp," %d:", p->attrib);
    switch (p->type) {
	case nodeNil: break;
	case nodeInt: fprintf(fp,PRTREG, p->value.i); break;
	case nodeReal: fprintf(fp,"%g", p->value.r); break;
	case nodeStr: fprintf(fp,"\"%s\"", p->value.s); break;
	case nodeData:
	    fprintf(fp,"%d[", p->value.d.size);
	    for (i = 0; i < p->value.d.size; i++)
	      fprintf(fp,"%2.2X", ((unsigned char*)p->value.d.data)[i]);
	    fprintf(fp,"]");
	    break;
	case nodeOpr: 
	    for (i = 0; i < p->value.sub.num; i++)
		cnt += print(p->value.sub.n[i], fp, tab, lev+1);
	    fprintf(fp,")");
	    break;
    }
    return cnt;
}

void printNode(Node *p, FILE *fp, char *tab[]) {
    if (fp == 0) fp = stdout;
    fprintf(fp, "\n[#%d]\n", print(p, fp, tab, 0));
}
