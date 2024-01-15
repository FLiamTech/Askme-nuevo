#include "askme.h"

#include <QApplication>
#include <QDebug>

#include <asignatura.h>
#include <cuestionario.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Askme w;
    w.show();
    /*
    Apunte *ap1 = new Apunte ("Funcion", "Una funcion de dependencia entre A y B");
    Apunte *ap2 = new Apunte ("Derivada", "Correspondencia entre el signo y el crecimiento o decrecimiento de la funcion original");

    Tema t("Ecuaciones de primer grado");
    t.agregarApunte(ap1);
    t.agregarApunte(ap2);

    //qDebug().noquote() << t.toString();

    Tema *t2 = new Tema("Electromagnetismo");
    t2->agregarApunte(new Apunte("Carga electrica", "Son cargas electricas que sirven para la electricidad"));
    t2->agregarApunte(new Apunte("Campo electrico", "Recion del espacio alrededor de una esfera"));
    t2->agregarApunte(new Apunte("Ley de Faraday", "Recion del espacio alrededor de una esfera"));
    t2->agregarApunte(new Apunte("Coulomb", "Recion del espacio alrededor de una esfera"));

    //qDebug().noquote() << t2->toString();

    Tema *t3 = new Tema("Optica");
    t3->agregarApunte(new Apunte("Luz", "Luz que hace ver bien"));
    t3->agregarApunte(new Apunte("Refreccion", "Cambio de direccion del un rayo de luz"));

    //qDebug().noquote() << t3->toString();

    Asignatura asignatura1("Fisica");
    asignatura1.agregarTema(t2);
    asignatura1.agregarTema(t3);

    qDebug().noquote() << asignatura1.toString();
    //Crea cuestionario
    Cuestionario quiz(t2);
    //Imprime lista de terminos
    qDebug().noquote() << quiz.terminos();
    //Obtener una pregunta e imprimir
    Pregunta *p = quiz.siguiente();
    //Imprimir
    //qDebug().noquote() << p->toString();
    //Responder
    p->responder("Carga electrica");
    //Volver a imprimir
    //qDebug().noquote() << p->toString();

    // Obtener otra pregunta e imprimir
    p = quiz.siguiente();
    p->responder("Incorrecto");
    //qDebug().noquote() << p->toString();

    quiz.finalizar();

    // Porcentaje
    qDebug().noquote() << "Porcentaje de respuestas correctas: " << quiz.score() << "%";

    foreach(Pregunta *p, quiz.preguntas())
    {
        if(p->respuesta())
        {
            qDebug().noquote() << p->apunte()->termino() << "\t" << p->correcto();
        }
    }
    */

    return a.exec();
}


/*
 * jsom - guardar los datos
 * archivo binario - tambien guardar los datos
 *
1. Cuando se agregue todo, guardar en un archivo csv. Para eso, crear un metodo en Askme.cpp denominado "guardar()",
   separada por "Tab"
2. Una vez guardada la informacion, modificar el metodo, cargar(), para que lea el archivo csv y cargue la informacion
   en m_asignaturas
3. Crear el formulario de lista de apuntes, para mostrar los apuntes guardados
*/

