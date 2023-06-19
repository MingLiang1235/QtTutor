/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>

#include "renderarea.h"
#include "utilities.h"
using namespace std;


/****************************************************************************/
ColorMatrix::ColorMatrix() : QObject(){
    //color_matrix = 0;
}

int ColorMatrix::set_color_matrix(unsigned char* chars, int size){
    int i = 0;
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;  // New line to display.
    ofstream color_outfile("D:\\s_c\\Project\\Decode_graphic\\log\\color_matrix.txt");
    if ( ! color_outfile){
        cout << "Oops! Unable to save color_outfile.txt." << endl;
    }
    else{
        for ( i = 0; i < size; i+=3){
            this->color_matrix[i] = chars[i+2];    //R
            this->color_matrix[i+1] = chars[i+1];  //G
            this->color_matrix[i+2] = chars[i];    //B
            cout.put(this->color_matrix[i]);  // Debug.
            cout.put(this->color_matrix[i+1]);  // Debug.
            cout.put(this->color_matrix[i+2]);  // Debug.
            color_outfile << color_matrix[i] << color_matrix[i+1] << color_matrix[i+2];  // Write to log file.
        }
    }

    return i;  // i <= size ? i : size;

}


/****************************************************************************/
int init_ch_array(CharArray* ca){
    ifstream decode_file("D:\\s_c\\Project\\Decode_graphic\\123.txt");
    if (!decode_file){
        cout << "Unable to open 123.txt." << endl;
    }
    unsigned char ch;

    unsigned char temp_chs[2000] = {0};
    int i = 0;
    while ( decode_file >> ch){
        //cout.put( ch );  //Debug.
        temp_chs[i] = ch;
        ++i;
        //temp_ch_vector.insert(raw_ch_vector.end(),ch);
    }
    ca->size = i;
    for ( int n = 0; n < i; ++n){
        ca->ch_array[n] = temp_chs[n];
    }
    return 0;
}
// End ColorMatrix.


CharArray::CharArray() : QObject(){
    init_ch_array(this);
}

int CharArray::set_pixel_array(int start, int stop){

    int size = this->size;
    int c = 0;
    ofstream absrct_shot_outfile("D:\\s_c\\Project\\Decode_graphic\\absrct_shot_out.txt");
    if (start <= size && start <= stop && stop <= size && size !=0){  //start=0,stop=0,size=0,not OK.
        for (int i = start; i <= stop; ++i ){
            this->pixel_array[i] = this->ch_array[i];
            //cout.put(this->pixel_array[i]);  // Debug.
            absrct_shot_outfile << pixel_array[i];  // Write to log file.
            c++;
        }
    }
    else{
        absrct_shot_outfile << "No data." << endl;
        return -1;
    }
    return c;
}


//! [0]
/****************************************************************************/

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{

    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    charArray = new CharArray();
    cout << "The size of ch array is : " << charArray->size << endl;
    //raw_ch_list = get_pixel_list(); //明显错误！类的静态成员不能在类的内部初始化，只能在外部初始化！
}
//! [0]

std::vector<char> RenderArea::get_pixel_vectort(){
    ifstream decode_file("D:\\s_c\\Project\\test_read_file\\test_read_file\\123.txt");
    if (!decode_file){
        cout << "Unable to open 123.txt." << endl;
    }
    char ch;
    const int max_length = 2000;
    char temp_chs[max_length] = {0};
    int i = 0;

    vector<char> temp_ch_vector;
    while ( decode_file.get(ch)){
        cout.put( ch );
        temp_chs[i] = ch;
        ++i;
        //temp_ch_vector.insert(raw_ch_vector.end(),ch);
    }

//    cout << "The raw_ch_vector size is : " << RenderArea::raw_ch_vector.size() << endl;
    //cout << "test 1 to char : " << char(69) << endl;
    //cout << "test direct out number 1 : " << 1 << endl;
    //return temp_chs;
    return temp_ch_vector;
//ForwardIterator first;
//ForwardIterator last;
//const char& x;
}

//! [1]
QSize RenderArea::minimumSizeHint() const
{
    return QSize(10, 10);
}
//! [1]

//! [2]
QSize RenderArea::sizeHint() const
{
    return QSize(300, 200);
}
//! [2]

//! [3]
void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}
//! [3]

//! [4]
void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}
//! [4]

//! [5]
void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
//! [5]

//! [6]
void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}
//! [6]

//! [7]
void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
//! [7]

//! [8]
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    const int side_pixels = 10;
    const int x_count = 16;  // 10*10*4 == 400, pixel_color_map is body is 400.(Head is 62,Foot is 40)(HEX).
    const int y_count = x_count;  // y_count == x_count.
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, side_pixels, side_pixels);

    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;
//! [8]

//! [9]
    QPainter painter(this);
    painter.setPen(pen);

    Utilities u = Utilities();

    ofstream log_file("D:\\s_c\\Project\\Decode_graphic\\log\\log.txt");
    log_file << showbase;  // Add '0x' prefix.

    int pixsize = this->charArray->set_pixel_array(62, 1085);  // 3E:62,43D:1085;
    cout << endl << "The size of pixel_color_map is : " << pixsize << endl;

    int r = 0, g = 0, b = 0, a = 0;
    //const QColor &color = QColor(u.get_random_int(0, 255), u.get_random_int(0, 255), u.get_random_int(0, 255), 255);
    QColor color = QColor(r, g, b, a);
    QBrush temp_brush = QBrush( Qt::green, Qt::SolidPattern );
    painter.setBrush(temp_brush);

    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);


//! [9]

    for (int x = x_count-1; x >= 0; --x){  // Matrix 初等变换
        for (int y = 0; y < y_count; ++y){
            painter.save();
            painter.translate(x * side_pixels, (y_count - y -1) * side_pixels);  // 上下颠倒
            //cout << noshowbase;  // Not add '0x' pre.

            log_file << "Pixel_array[" << dec << 4*x*x_count + 4*y << "]: " << charArray->pixel_array[4*x + 4*y] << endl;  // dec: decimal

            g = this->charArray->pixel_array[4 * x * x_count + 4 * y];
            r = this->charArray->pixel_array[4 * x * x_count + 4 * y + 1];
            a = this->charArray->pixel_array[4 * x * x_count + 4 * y + 2];
            b = this->charArray->pixel_array[4 * x * x_count + 4 * y + 3];  // Every package is (Alpha,B,G,R), so Sum is 4.

            log_file << "Loca:" << x << "," << y_count - y - 1 << ". RGB: " << hex << r << '|' << g << '|' << b << '|' << a << endl;  // hex: heximal
            //log_file << "Loca:" << x << "," << y << ". RGB: " << showbase << hex << r << '|' << g << '|' << b << '|' << a << endl;
            color.setRed(r);
            color.setGreen(g);
            color.setBlue(b);
            color.setAlpha(a);
            temp_brush.setColor(color);

            //cout << noshowbase;

            //temp_brush.setColor(QColor(u.get_random_int(0, 255), u.get_random_int(0, 255), u.get_random_int(0, 255), 255));
            painter.setBrush(temp_brush);
            painter.drawRect(rect);
            painter.restore();
        }
    }



////! [10]
//    for (int x = 0; x < width(); x += 100) {
//        for (int y = 0; y < height(); y += 100) {
//            painter.save();
//            painter.translate(x, y);
////! [10] //! [11]
//            if (transformed) {
//                painter.translate(50, 50);
//                painter.rotate(60.0);
//                painter.scale(0.6, 0.9);
//                painter.translate(-50, -50);
//            }
////! [11]

////! [12]
//            switch (shape) {
//            case Line:
//                painter.drawLine(rect.bottomLeft(), rect.topRight());
//                break;
//            case Points:
//                painter.drawPoints(points, 4);
//                break;
//            case Polyline:
//                painter.drawPolyline(points, 4);
//                break;
//            case Polygon:
//                painter.drawPolygon(points, 4);
//                break;
//            case Rect:
//                painter.drawRect(rect);
//                break;
//            case RoundedRect:
//                painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
//                break;
//            case Ellipse:
//                painter.drawEllipse(rect);
//                break;
//            case Arc:
//                painter.drawArc(rect, startAngle, arcLength);
//                break;
//            case Chord:
//                painter.drawChord(rect, startAngle, arcLength);
//                break;
//            case Pie:
//                painter.drawPie(rect, startAngle, arcLength);
//                break;
//            case Path:
//                painter.drawPath(path);
//                break;
//            case Text:
//                painter.drawText(rect, Qt::AlignCenter, tr("Qt by\nNokia"));
//                break;
//            case Pixmap:
//                painter.drawPixmap(10, 10, pixmap);
//            }
////! [12] //! [13]
//            painter.restore();
//        }
//    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    //painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
//! [13]
