// --------------------------
// projects/c++/graph/Graph.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector

// -----
// Graph
// -----

class Graph {
 public:
  // --------
  // typedefs
  // --------

  typedef int vertex_descriptor; 
  typedef pair<vertex_descriptor,vertex_descriptor> edge_descriptor; 

  typedef vector< vertex_descriptor>::iterator vertex_iterator;  
  typedef vector< edge_descriptor>::iterator edge_iterator;     
  typedef vector< vertex_descriptor>::iterator adjacency_iterator; 

  typedef std::size_t vertices_size_type;
  typedef std::size_t edges_size_type;

 public:
  // --------
  // add_edge
  // --------

  /**
   * @param v1 vertex descriptor
   * @param v2 vertex descriptor
   * @param graph graph by reference
   * @return pair as a tuple with edge ad true if added, false otherwise
   */
  friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor v1, vertex_descriptor v2, Graph& graph) {
    
    edge_descriptor ed = 0;
    bool            b  = false;
    return std::make_pair(ed, b);}

  // ----------
  // add_vertex
  // ----------

  /**
   * @param graph by reference
   * @return vd a vertex descriptor
   */
  friend vertex_descriptor add_vertex (Graph& graph) {
    vertex_descriptor vd = graph.v.size();
    graph.v.push_back(vd);
    graph.g.push_back(g);
    return vd;}

  // -----------------
  // adjacent_vertices
  // -----------------

  /**
   * @param vd vertex descriptor
   * @param graph const graph by reference
   * @return pair of iterators
   */
  friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd, const Graph& graph) {
    // <your code>
    static int a [] = {0, 0};     // dummy data
    adjacency_iterator b = a;
    adjacency_iterator e = a + 2;
    return std::make_pair(b, e);}

  // ----
  // edge
  // ----

  /**
   * @param v1 vertex descriptor
   * @param v2 vertex descriptor
   * @param graph const graph by reference
   * @return pair with an edge and true if it exists, false otherwise
   */
  friend std::pair<edge_descriptor, bool> edge (vertex_descriptor v1, vertex_descriptor v2, const Graph& graph) {
    // <your code>
    edge_descriptor ed = 0;
    bool            b  = true;
    return std::make_pair(ed, b);}

  // -----
  // edges
  // -----

  /**
   * @param graph const graph by reference
   * @return pair of edge iterators
   */
  friend std::pair<edge_iterator, edge_iterator> edges (const Graph& graph) {
    // <your code>
    static int a [] = {0, 0};     // dummy data
    edge_iterator b = a;
    edge_iterator e = a + 2;
    return std::make_pair(b, e);}

  // ---------
  // num_edges
  // ---------

  /**
   * @param graph const graph by reference
   * @return s number of edges in graph
   */
  friend edges_size_type num_edges (const Graph& graph) {
    // <your code>
    edges_size_type s = 1; // fix
    return s;}

  // ------------
  // num_vertices
  // ------------

  /**
   * @param graph const graph by reference
   * @return s number of vertices in graph
   */
  friend vertices_size_type num_vertices (const Graph& graph) {
    // <your code>
    vertices_size_type s = 1; // fix
    return s;}

  // ------
  // source
  // ------

  /**
   * @param ed edge descriptor
   * @param graoh const graph by reference
   * @return v source of an edge
   */
  friend vertex_descriptor source (edge_descriptor ed, const Graph& graph) {
    // <your code>
    vertex_descriptor v = 0; // fix
    return v;}

  // ------
  // target
  // ------

  /**
   * @param ed edge descriptor
   * @param graph const graph by reference
   * @return v target of an edge
   */
  friend vertex_descriptor target (edge_descriptor ed, const Graph& graph) {
    // <your code>
    vertex_descriptor v = 0; // fix
    return v;}

  // ------
  // vertex
  // ------

  /**
   * @param s vertices size type
   * @param graph const graph by reference
   * @return vd a vertex from the graph
   */
  friend vertex_descriptor vertex (vertices_size_type s, const Graph& graph) {
    // <your code>
    vertex_descriptor vd = 0; // fix
    return vd;}

  // --------
  // vertices
  // --------

  /**
   * @param graph const graph by reference
   * @return pair of iterators
   */
  friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& graph) {
    // <your code>
    static int a [] = {0, 0};     // dummy data
    vertex_iterator b = a;
    vertex_iterator e = a + 2;
    return std::make_pair(b, e);}

 private:
  // ----
  // data
  // ----

  std::vector< std::vector<vertex_descriptor> > g; // something like this
  std::vector< vertex_descriptor > v;
  std::vector< edge_descriptor > e;

  // -----
  // valid
  // -----

  /**
   * @return true if graph is valid, false otherwise
   */
  bool valid () const {
    return true;}

 public:
  // ------------
  // constructors
  // ------------

  /**
   * <your documentation>
   */
  Graph () {
    
    assert(valid());}

  // Default copy, destructor, and copy assignment
  // Graph  (const Graph<T>&);
  // ~Graph ();
  // Graph& operator = (const Graph&);
};

#endif // Graph_h
