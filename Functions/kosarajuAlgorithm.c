#include "DFS.c"

static int cnt, pre[1000];
static int cntt, post[1000];
static vertex vv[1000];


char** copyNames (char** names, int V){
	char** namesCopy = (char**) malloc (sizeof(char*)*V);
	int i;
	for (i = 0 ; i<V ; i++){
		namesCopy[i] = (char*) malloc (sizeof(char)*100);
	}

	for (i=0 ; i<V ; i++) {
		strcpy(namesCopy[i], names[i]);
	}
		return namesCopy;
}

pGraph createReverseGraph( pGraph G,char** names) {
   char** namesCopy = copyNames(names, G->V);
   pGraph GR = graphInit( G->V, namesCopy);
   for (vertex v = 0; v < G->V; ++v){
      link a = G->adj[v];
      while(a != NULL){
         graphInsertArc(GR, namesCopy[a->w], namesCopy[v] );
         a = a->next;
      }
      
   }      
   return GR;
}

// static void dfsRstrongCompsK( pGraph G, vertex v, int *sc, int k) 
// { 
//    sc[v] = k;
//    for (link a = G->adj[v]; a != NULL; a = a->next)
//       if (sc[a->w] == -1) 
//          dfsRstrongCompsK( G, a->w, sc, k);
// };

// static void dfsR( pGraph GR, vertex v) 
// { 
//    pre[v] = cnt++; 
//    for (link a = GR->adj[v]; a != NULL; a = a->next)
//       if (pre[a->w] == -1) 
//          dfsR( GR, a->w); 
//    post[v] = cntt++;
// };
    
// int GRAPHstrongCompsK( pGraph G, int *sc,char** names,char** input) // recebe o grafo e um vetor que servirá para mapear os vértices fortemente conexos
// {
//    // fase 1:
//    pGraph GR = GRAPHreverse( G,names,input);
//    cnt = cntt = 0;
//    vertex v; 
//    for (v = 0; v < GR->V; ++v) pre[v] = -1;
//    for (v = 0; v < GR->V; ++v) 
//       if (pre[v] == -1)
//          dfsR( GR, v); 
//    for (v = 0; v < GR->V; ++v) 
//       vv[post[v]] = v;
//    // vv[0..V-1] é permutação de GR em pós-ordem

//    // fase 2:
//    for (v = 0; v < G->V; ++v) sc[v] = -1;
//    int k = 0;
//    for (int i = G->V-1; i >= 0; --i) {
//       v = vv[i];
//       if (sc[v] == -1) { // nova etapa
//          dfsRstrongCompsK( G, v, sc, k);
//          k++;
//       }
//    };
//    if(k == 1){
//     printf("O grafo é fortemente conexo\n");
//    }else{
//     printf("O grafo não é fortemente conexo\n");}

//    return k;
// };