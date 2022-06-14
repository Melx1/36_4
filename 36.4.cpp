#include <QApplication>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QPainter>

class QCircle : public QLabel {
    Q_OBJECT
public:
    QCircle(QWidget *parent = nullptr) : QLabel(parent) {};

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setPen (QPen(colorCircle, Qt::SolidLine));
        painter.setBrush(QBrush(colorCircle, Qt::SolidPattern));
        QPoint center(width()/2,height()/2);
        int rad = qMin(width()/4,height()/4);
        painter.drawEllipse(center,rad,rad);
    }

public slots:
    void setColor(int value) {
        if (value < 33) {
            colorCircle = Qt::green;
            this->update();
            return;
        }
        if (value < 66) {
            colorCircle = Qt::yellow;
            this->update();
            return;
        }
        else {
            colorCircle = Qt::red;
            this->update();
            return;
        }
    };

private:
    QColor colorCircle = Qt::green;
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget widget;
    widget.resize(640, 480);
    widget.setWindowTitle("Magic circle");

    auto *gridLayout = new QGridLayout(&widget);

    //Create circle
    auto *circle = new QCircle(&widget);
    gridLayout->addWidget(circle);

    // Create a horizontal slider
    // with the range between 0 and 100, and a starting value of 0
    auto *slider = new QSlider(&widget);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 160, 180, 30);
    gridLayout->addWidget(slider);

    QObject::connect(slider, SIGNAL (valueChanged(int)), circle, SLOT (setColor(int)));

    widget.show();

    return app.exec();
}

#include <36.4.moc>