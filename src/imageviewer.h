#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QImage>
#include <QTransform>
#include <QWidget>
#include <qpoint.h>

class ImageViewer : public QWidget
{
    Q_OBJECT

signals:
    void doubleClicked(const QPointF& pos);
    void rightClicked(const QPointF& pos);
    void mouseMoved(const QPointF& pos);

public:
    explicit ImageViewer(QWidget* parent = nullptr);

    void setImage(const QImage& image);
    QImage getImage() const
    {
        return m_image;
    }
    QPointF mapToImage(const QPointF& pos) const;
    QPointF mapFromImage(const QPointF& pos) const;
    double getScale() const
    {
        return m_transform.m11();
    }
    void clearData()
    {
        setImage(QImage());
    }
    void fitToView();

protected:
    void paintEvent(QPaintEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void contextMenuEvent(QContextMenuEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    QImage m_image;
    QTransform m_transform;
    QPointF m_lastMousePos;
    bool m_isDragging;
};

#endif // IMAGEVIEWER_H
