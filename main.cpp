#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <iostream>
#include <stdlib.h>
#include <time.h>
QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Clase para graficar
    QLineSeries *series = new QLineSeries();
    srand(time(NULL));
    int num[10];
    for(int i=0;i<10;i++){ //Llenamos el arreglo con numeros aleatorios y lo imprimimos en pantalla
        num[i]=rand()%20;
        std::cout<<"Num "<<i<<": "<<num[i]<<std::endl;
    }
    //En este ciclo metemos los numeros que se van a graficar, en este caso son aleatorios
    for(int i=0;i<10;i++)
        series->append(i,num[i]);

    //Para mostrar los datos necesitamos una instancia de QChart
    QChart *chart = new QChart();
    chart->legend()->hide(); //muestra la linea del color cuando ponemos show para saber cual se está referenciando
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Práctica 1");
    //Agregamos a un chartview la instancia de qchart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //Para mostrarlo en ventana
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
    return a.exec();
}
