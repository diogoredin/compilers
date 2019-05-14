/* $Id: node.h,v 1.4 2012/09/12 17:24:33 prs Exp $ */
#ifndef __NODE_H__ 
#define __NODE_H__ 

#include <stdio.h> /* for FILE argument to printNode and scanNode */

#ifdef _64bits_
typedef long long regint;
#define PRTREG "%lld"
#define strtol strtoll
#else
typedef int regint;
#define PRTREG "%d"
#endif


typedef enum{ nodeNil, nodeInt, nodeStr, nodeReal, nodeData, nodeOpr }NodeType; 
 
typedef struct typeNode Node;
struct typeNode { 
    NodeType type;		/* type of node */ 
    int   user;			/* pointer to any user data */ 
    int   attrib;		/* user defined attributes */
    int   line;			/* input file parse line */
    void *state;		/* for the instruction selector (burg) */ 
    int   info;			/* specific info such as type or register used */
    union {
      regint i;			/* value of literal integer */ 
      double r;			/* value of literal real number */ 
      char *s;			/* value of literal string (null terminated) */ 
      struct {
	int size;		/* size of data */
	void *data;		/* pointer to data */ 
      } d;			/* value of any opaque data (untyped) */
      struct {
	int num;		/* number os subnode in this node */
	Node *n[1];  		/* subnodes (expandable) */ 
      } sub;
    } value;
}; 

/* prototypes */
Node *uniNode(int attrib, Node *n1);
Node *binNode(int attrib, Node *n1, Node *n2);
Node *triNode(int attrib, Node *n1, Node *n2, Node *n3);
Node *subNode(int attrib, int nops, ...);
Node *seqNode(int oper, int nops, ...);
Node *nilNode(int attrib);
Node *intNode(int attrib, regint i);
Node *realNode(int attrib, double d);
Node *dataNode(int attrib, int size, void *user);
Node *strNode(int attrib, char *s);
Node *addNode(Node *base, Node *node, unsigned pos);
Node *removeNode(Node *base, unsigned pos);
int  userNode(Node *p, int user); // o parametro user era void*
void freeNode(Node *p);
void printNode(Node *p, FILE *fp, char *tab[]);
Node *newNode(NodeType t, int attrib, int nops);

#define SUB(x)	value.sub.n[x]

/* defines for pburg */
#define STATE_TYPE void*
#define NODEPTR_TYPE Node*
#define OP_LABEL(p) ((p)->attrib)
#define LEFT_CHILD(p)  ((p)->type == nodeOpr && (p)->value.sub.num > 0 ? (p)->value.sub.n[0] : 0)
#define RIGHT_CHILD(p) ((p)->type == nodeOpr && (p)->value.sub.num > 1 ? (p)->value.sub.n[1] : 0)
#define STATE_LABEL(p) ((p)->state)
#define PLACE(p) ((p)->info)
 
#endif /* __NODE_H__ */
