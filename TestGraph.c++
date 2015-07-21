// --------------------------------
// projects/g++/graph/TestGraph.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp"  // adjacency_list
#include "boost/graph/topological_sort.hpp"// topological_sort

#include "gtest/gtest.h"

#include "Graph.h"

using namespace std;

using testing::Test;
using testing::Types;

// ---------
// TestGraph
// ---------

template <typename G>
struct TestGraph : Test {
  // --------
  // typedefs
  // --------

  typedef          G                     graph_type;
  typedef typename G::vertex_descriptor  vertex_descriptor;
  typedef typename G::edge_descriptor    edge_descriptor;
  typedef typename G::vertex_iterator    vertex_iterator;
  typedef typename G::edge_iterator      edge_iterator;
  typedef typename G::adjacency_iterator adjacency_iterator;
  typedef typename G::vertices_size_type vertices_size_type;
  typedef typename G::edges_size_type    edges_size_type;
};

// directed, sparse, unweighted
// possibly connected
// possibly cyclic
typedef Types<
  boost::adjacency_list<boost::setS, boost::vecS, boost::directedS>,
  Graph>
graph_types;
/*
  typedef Types<boost::adjacency_list<boost::setS, boost::vecS, boost::directedS>>
        graph_types;
*/
TYPED_TEST_CASE(TestGraph, graph_types);

// --------
// add_edge
// --------

TYPED_TEST(TestGraph, add_edge1) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

  graph_type g;

  vertex_descriptor vdA = add_vertex(g);
  vertex_descriptor vdB = add_vertex(g);

  bool b = add_edge(vdA, vdB, g).second;
  ASSERT_TRUE(b);}

TYPED_TEST(TestGraph, add_edge2) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

  graph_type g;

  vertex_descriptor vdA = add_vertex(g);
  vertex_descriptor vdB = add_vertex(g);
  vertex_descriptor vdC = add_vertex(g);

  bool b = add_edge(vdA, vdB, g).second;
  ASSERT_TRUE(b);
  bool c = add_edge(vdA, vdC, g).second;
  ASSERT_TRUE(c);
  bool d = add_edge(vdA, vdC, g).second;
  ASSERT_FALSE(d);}

TYPED_TEST(TestGraph, add_edge3) {
  typedef typename TestFixture::graph_type         graph_type;

  graph_type g;

  bool a = add_edge(9, 10, g).second;
  ASSERT_EQ(num_vertices(g), 11);
  ASSERT_TRUE(a);

  bool b = add_edge(9, 10, g).second;
  ASSERT_FALSE(b);}

// ----------
// add_vertex
// ----------

TYPED_TEST(TestGraph, add_vertex_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
    
  add_vertex(g);
  ASSERT_EQ(1, num_vertices(g));
}

TYPED_TEST(TestGraph, add_vertex_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
    
  auto v1 = add_vertex(g);
  auto v2 = add_vertex(g);
  ASSERT_EQ(2, num_vertices(g));
  ASSERT_NE(v1, v2);
}

TYPED_TEST(TestGraph, add_vertex_3) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
    
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  ASSERT_EQ(4, num_vertices(g));
}



// ----
// edge
// ----

TYPED_TEST(TestGraph, edge_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  auto p = edge(u, v, g);
  ASSERT_FALSE(p.second);
}

TYPED_TEST(TestGraph, edge_2) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    
  graph_type g;
  vertex_descriptor u = 0;
  vertex_descriptor v = 1;
  auto p1 = add_edge(u, v, g);
  auto p2 = edge(u, v, g);
  ASSERT_EQ(p2.first, p1.first);
}

TYPED_TEST(TestGraph, edge_3) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    
  graph_type g;
  vertex_descriptor u = 0;
  vertex_descriptor v = 1;
  vertex_descriptor w = 2;
  add_edge(u, v, g);
  add_edge(v, w, g);
  auto p = edge(u, w, g);
  ASSERT_FALSE(p.second);
}

// -----
// edges
// -----

TYPED_TEST(TestGraph, edges_1) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    
  graph_type g;
  vertex_descriptor u = 0;
  vertex_descriptor v = 1;
  add_edge(u, v, g);
  auto p = edges(g);
  ASSERT_EQ(p.second, ++p.first);
}

TYPED_TEST(TestGraph, edges_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  add_vertex(g);
  add_vertex(g);
  auto p = edges(g);
  ASSERT_EQ(p.second, p.first);
}

TYPED_TEST(TestGraph, edges_3) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    
  graph_type g;
  vertex_descriptor u = 0;
  vertex_descriptor v = 1;
  vertex_descriptor w = 2;
  vertex_descriptor x = 3;
  add_edge(u, v, g);
  add_edge(v, w, g);
  add_edge(w, x, g);
  add_edge(x, u, g);
  auto p = edges(g);
  int i = 4;
  while (i-- > 0) {
    ++p.first;
  }
  ASSERT_EQ(p.second, p.first);
}

// ---------
// num_edges
// ---------

TYPED_TEST(TestGraph, num_edges_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  add_edge(u, v, g);
  auto n = num_edges(g);
  ASSERT_EQ(1, n);
}

TYPED_TEST(TestGraph, num_edges_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto n = num_edges(g);
  ASSERT_EQ(0, n);
}

TYPED_TEST(TestGraph, num_edges_3) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  add_edge(u, v, g);
  add_edge(v, u, g);
  auto n = num_edges(g);
  ASSERT_EQ(2, n);
}

// ------------
// num_vertices
// ------------

TYPED_TEST(TestGraph, num_vertices_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto n = num_vertices(g);
  ASSERT_EQ(0, n);
}

TYPED_TEST(TestGraph, num_vertices_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  auto n = num_vertices(g);
  ASSERT_EQ(3, n);
}

TYPED_TEST(TestGraph, num_vertices_3) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    
  graph_type g;
  vertex_descriptor u = 0;
  vertex_descriptor v = 1;
  add_edge(u, v, g);
  auto n = num_vertices(g);
  ASSERT_EQ(2, n);
}

TYPED_TEST(TestGraph, num_vertices_4) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    
  graph_type g;
  vertex_descriptor u = 0;
  vertex_descriptor v = 1;
  add_edge(u, v, g);
  add_edge(v, u, g);
  auto n = num_vertices(g);
  ASSERT_EQ(2, n);
}

// ------
// source
// ------

TYPED_TEST(TestGraph, source_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  auto p = add_edge(u, v, g);
  auto ud = source(p.first, g);
  ASSERT_EQ(u, ud);
}

TYPED_TEST(TestGraph, source_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  auto p = add_edge(u, v, g);
  auto ud = source(p.first, g);
  ASSERT_NE(v, ud);
}

TYPED_TEST(TestGraph, source_3) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  auto w = add_vertex(g);
  auto p1 = add_edge(u, v, g);
  auto p2 = add_edge(v, w, g);
  auto ud = source(p1.first, g);
  auto vd = source(p2.first, g);
  ASSERT_EQ(u, ud);
  ASSERT_EQ(v, vd);
}

// ------
// target
// ------

TYPED_TEST(TestGraph, target_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  auto p = add_edge(u, v, g);
  auto vd = target(p.first, g);
  ASSERT_EQ(v, vd);
}

TYPED_TEST(TestGraph, target_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  auto p = add_edge(u, v, g);
  auto vd = target(p.first, g);
  ASSERT_NE(u, vd);
}

TYPED_TEST(TestGraph, target_3) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  auto v = add_vertex(g);
  auto w = add_vertex(g);
  auto p1 = add_edge(u, v, g);
  auto p2 = add_edge(v, w, g);
  auto vd = target(p1.first, g);
  auto wd = target(p2.first, g);
  ASSERT_EQ(v, vd);
  ASSERT_EQ(w, wd);
}

// ------
// vertex
// ------

TYPED_TEST(TestGraph, vertex_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto u = add_vertex(g);
  ASSERT_EQ(u, vertex(0, g));
}

TYPED_TEST(TestGraph, vertex_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  ASSERT_EQ(2, vertex(2, g));
}

TYPED_TEST(TestGraph, vertex_3) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  auto u = add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  ASSERT_EQ(u, vertex(5, g));
}

// --------
// vertices
// --------

TYPED_TEST(TestGraph, vertices_1) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  auto p = vertices(g);
  ASSERT_EQ(p.first, p.second);
}

TYPED_TEST(TestGraph, vertices_2) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  add_vertex(g);
  add_vertex(g);
  auto p = vertices(g);
  ASSERT_EQ(p.second, ++++p.first);
}

TYPED_TEST(TestGraph, vertices_3) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  add_vertex(g);
  add_vertex(g);
  add_vertex(g);
  auto p = vertices(g);
  ASSERT_EQ(p.second, ++++++p.first);
}

// -----------
// constructor
// -----------

TYPED_TEST(TestGraph, constructor) {
  typedef typename TestFixture::graph_type         graph_type;
    
  graph_type g;
  ASSERT_EQ(0, num_vertices(g));
}


// -----------------
// adjacent_vertices
// -----------------

TYPED_TEST(TestGraph, test_adjacent_vertices) {
  typedef typename TestFixture::graph_type         graph_type;
  typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

  typedef typename TestFixture::adjacency_iterator adjacency_iterator;


  graph_type g;

  vertex_descriptor vdA = add_vertex(g);
  vertex_descriptor vdB = add_vertex(g);
  vertex_descriptor vdC = add_vertex(g);

  add_edge(vdA, vdB, g);
  add_edge(vdA, vdC, g);

  pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
  adjacency_iterator                           b = p.first;
  adjacency_iterator                           e = p.second;
  if (b != e) {
    vertex_descriptor vd = *b;
    ASSERT_EQ(vdB, vd);}
  ++b;
  if (b != e) {
    vertex_descriptor vd = *b;
    ASSERT_EQ(vdC, vd);}
  ++b;
  ASSERT_EQ(e, b);}
