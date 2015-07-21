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
  typedef std::pair<vertex_descriptor,vertex_descriptor> edge_descriptor; 

  typedef std::vector<vertex_descriptor>::const_iterator vertex_iterator;  
  typedef std::vector<edge_descriptor>::const_iterator edge_iterator;     
  typedef std::vector<vertex_descriptor>::const_iterator adjacency_iterator; 

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
   * @return pair as a tuple with edge and true if added, false otherwise
   */
  friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor v1, vertex_descriptor v2, Graph& graph) {
    edge_descriptor ed = std::make_pair(v1, v2);
    bool            b  = false;
    graph._e.push_back(ed);
    graph._g[ed.first].push_back(ed.second);
    return std::make_pair(ed, b);}

  // ----------
  // add_vertex
  // ----------

  /**
   * @param graph by reference
   * @return v a vertex descriptor
   */
  friend vertex_descriptor add_vertex (Graph& graph) {
    vertex_descriptor v = graph._v.size();
    graph._v.push_back(v);
    graph._g.push_back(std::vector< vertex_descriptor>());
    return v;}

  // -----------------
  // adjacent_vertices
  // -----------------

  /**
   * @param vd vertex descriptor
   * @param graph const graph by reference
   * @return pair of iterators
   */
  friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd, const Graph& graph) {
    adjacency_iterator b = graph._g[vd].begin();
    adjacency_iterator e = graph._g[vd].end();
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
    edge_descriptor ed = std::make_pair(v1, v2);
    bool            b  = true;

    std::vector<edge_descriptor>::const_iterator b1 = graph._e.begin();
    std::vector<edge_descriptor>::const_iterator e = graph._e.end();

    while(b1 != e){
      if (*b1 == ed){
        b = true;
        break;
      }
      ++b1;
    }    
    return std::make_pair(ed, b);}

  // -----
  // edges
  // -----

  /**
   * @param graph const graph by reference
   * @return pair of edge iterators
   */
  friend std::pair<edge_iterator, edge_iterator> edges (const Graph& graph) {
    edge_iterator b = graph._e.begin();
    edge_iterator e = graph._e.end();
    return std::make_pair(b, e);}

  // ---------
  // num_edges
  // ---------

  /**
   * @param graph const graph by reference
   * @return s number of edges in graph
   */
  friend edges_size_type num_edges (const Graph& graph) {
    edges_size_type s = graph._e.size();
    return s;}

  // ------------
  // num_vertices
  // ------------

  /**
   * @param graph const graph by reference
   * @return s number of vertices in graph
   */
  friend vertices_size_type num_vertices (const Graph& graph) {
    vertices_size_type s = graph._v.size(); 
    return s;}

  // ------
  // source
  // ------

  /**
   * @param ed edge descriptor
   * @param graoh const graph by reference
   * @return v source of an edge
   */
  friend vertex_descriptor source (edge_descriptor e, const Graph& graph) {
    vertex_descriptor v = e.first; 
    return v;}

  // ------
  // target
  // ------

  /**
   * @param ed edge descriptor
   * @param graph const graph by reference
   * @return v target of an edge
   */
  friend vertex_descriptor target (edge_descriptor e, const Graph& graph) {
    vertex_descriptor v = e.second; 
    return v;}

  // ------
  // vertex
  // ------

  /**
   * @param s vertices size type
   * @param graph const graph by reference
   * @return v a vertex from the graph
   */
  friend vertex_descriptor vertex (vertices_size_type x, const Graph& graph) {
    vertex_descriptor v = graph._v[x];
    return v;}

  // --------
  // vertices
  // --------

  /**
   * @param graph const graph by reference
   * @return pair of vertex iterators
   */
  friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& graph) {
    vertex_iterator b = graph._v.begin();
    vertex_iterator e = graph._v.end();
    return std::make_pair(b, e);}

 private:
  // ----
  // data
  // ----

  std::vector< std::vector<vertex_descriptor> > _g; // something like this
  std::vector< vertex_descriptor > _v;
  std::vector< edge_descriptor > _e;

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
   * Constructs the data members with the private data
   */
  Graph () {
    _g = std::vector< std::vector<vertex_descriptor> >();
    _v = std::vector< vertex_descriptor >();
    _e = std::vector< edge_descriptor >();;
    assert(valid());}

  // Default copy, destructor, and copy assignment
  // Graph  (const Graph<T>&);
  // ~Graph ();
  // Graph& operator = (const Graph&);
};

#endif // Graph_h
