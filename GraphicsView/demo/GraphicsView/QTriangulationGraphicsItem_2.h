
#ifndef CGAL_Q_TRIANGULATION_GRAPHICS_ITEM_2_H
#define CGAL_Q_TRIANGULATION_GRAPHICS_ITEM_2_H

#include <CGAL/Bbox_2.h>
#include <CGAL/apply_to_range.h>
#include "QPainterOstream.h"
#include "QGraphicsItem_2.h"
#include "QConverter.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

namespace CGAL {


template <typename T>
class QTriangulationGraphicsItem_2 : public QGraphicsItem_2
{
public:
  QTriangulationGraphicsItem_2(T* t_);

  void modelChanged();

public:
  QRectF boundingRect() const;
  
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  
  virtual void operator()(typename T::Face_handle fh);

  const QPen& verticesPen() const
  {
    return vertices_pen;
  }

  void setVerticesPen(const QPen& pen)
  {
    vertices_pen = pen;
  }

  bool drawVertices() const
  {
    return draw_vertices;
  }

  void setDrawVertices(const bool b)
  {
    draw_vertices = b;
    update();
  }

  bool drawEdges() const
  {
    return draw_edges;
  }

  void setDrawEdges(const bool b)
  {
    draw_edges = b;
    update();
  }

protected:
  virtual void drawAll(QPainter *painter);
  void paintVertices(QPainter *painter);
  void paintOneVertex(const typename T::Point& point);
  void updateBoundingBox();

  T * t;
  QPainter* m_painter;

  typename T::Vertex_handle vh;
  typename T::Point p;
  CGAL::Bbox_2 bb;  
  bool bb_initialized;
  QRectF bounding_rect;

  QPen vertices_pen;
  bool draw_vertices;
  bool draw_edges;
};


template <typename T>
QTriangulationGraphicsItem_2<T>::QTriangulationGraphicsItem_2(T * t_)
  :  t(t_), bb(0,0,0,0), bb_initialized(false),
     draw_edges(true), draw_vertices(true)
{
  setVerticesPen(QPen(Qt::red, 3.));
  if(t->number_of_vertices() == 0){
    this->hide();
  }
  updateBoundingBox();
  setZValue(3);
}

template <typename T>
QRectF 
QTriangulationGraphicsItem_2<T>::boundingRect() const
{
  return bounding_rect;
}


template <typename T>
void 
QTriangulationGraphicsItem_2<T>::operator()(typename T::Face_handle fh)
{
  QConverter<K> convert;

  if(draw_edges) {
    for (int i=0; i<3; i++) {
      if (fh < fh->neighbor(i) || t->is_infinite(fh->neighbor(i))){
        m_painter->setPen(this->pen());
        (*m_painter) << t->segment(fh,i);
      }
    }
  }
  if(draw_vertices) {
    for (int i=0; i<3; i++) {
      paintOneVertex(fh->vertex(i)->point());
    }
  }
}

template <typename T>
void 
QTriangulationGraphicsItem_2<T>::drawAll(QPainter *painter)
{
  if(drawEdges()) {
    for(typename T::Finite_edges_iterator eit = t->finite_edges_begin();
        eit != t->finite_edges_end();
        ++eit){
      (*painter) << t->segment(*eit);
    }
  }
  paintVertices(painter);
}

template <typename T>
void 
QTriangulationGraphicsItem_2<T>::paintVertices(QPainter *painter)
{
  if(drawVertices()) {
    QConverter<K> convert;

    painter->setPen(verticesPen());
    QMatrix matrix = painter->matrix();
    painter->resetMatrix();
    for(typename T::Finite_vertices_iterator it = t->finite_vertices_begin();
        it != t->finite_vertices_end();
        it++){
      QPointF point = matrix.map(convert(it->point()));
      painter->drawPoint(point);
    }
  }
}

template <typename T>
void 
QTriangulationGraphicsItem_2<T>::paintOneVertex(const typename T::Point& point)
{
  QConverter<K> convert;

  m_painter->setPen(this->verticesPen());
  QMatrix matrix = m_painter->matrix();
  m_painter->resetMatrix();
  m_painter->drawPoint(matrix.map(convert(point)));
  m_painter->setMatrix(matrix);
}

template <typename T>
void 
QTriangulationGraphicsItem_2<T>::paint(QPainter *painter, 
                                       const QStyleOptionGraphicsItem *option,
                                       QWidget * widget)
{
  painter->setPen(this->pen());
//   painter->drawRect(boundingRect());
  if ( t->dimension()<2 || option->exposedRect.contains(boundingRect()) ) {
    drawAll(painter);
  } else {
    m_painter = painter;
    CGAL::apply_to_range (*t, 
                          typename T::Point(option->exposedRect.left(),
                                            option->exposedRect.bottom()), 
                          typename T::Point(option->exposedRect.right(),
                                            option->exposedRect.top()), 
                          *this);
  }
}

// We let the bounding box only grow, so that when vertices get removed
// the maximal bbox gets refreshed in the GraphicsView
template <typename T>
void 
QTriangulationGraphicsItem_2<T>::updateBoundingBox()
{
  prepareGeometryChange();
  if(t->number_of_vertices() == 0){
    bb = Bbox_2(0,0,0,0);
    bb_initialized = false;
    return;
  } else if(! bb_initialized){
    bb = t->finite_vertices_begin()->point().bbox();
    bb_initialized = true;
  }
  
  if(t->dimension() <2){
    for(typename T::Finite_vertices_iterator it = t->finite_vertices_begin();
	it != t->finite_vertices_end();
	++it){
      bb = bb + it->point().bbox();
    }
  } else {
    typename T::Vertex_handle inf = t->infinite_vertex();
    typename T::Vertex_circulator vc = t->incident_vertices(inf), done(vc);
    do {
      bb = bb + vc->point().bbox();
      ++vc;
    } while(vc != done);
  }
  bounding_rect = QRectF(bb.xmin(),
                         bb.ymin(),
                         bb.xmax()-bb.xmin(),
                         bb.ymax()-bb.ymin());
}


template <typename T>
void 
QTriangulationGraphicsItem_2<T>::modelChanged()
{
  if((t->number_of_vertices() == 0) ){
    this->hide();
  } else if((t->number_of_vertices() > 0) && (! this->isVisible())){
    this->show();
  }
  updateBoundingBox();
  update();
}


} // namespace CGAL

#endif // CGAL_Q_TRIANGULATION_GRAPHICS_ITEM_2_H
