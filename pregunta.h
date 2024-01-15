#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <apunte.h>

class Pregunta
{
public:
    Pregunta();
    Pregunta(Apunte *apunte);

    bool correcto() const;
    bool respuesta() const;
    void setCorrecto(bool newCorrecto);
    void setRespuesta(bool newRespuesta);
    Apunte *apunte() const;
    void setApunte(Apunte *newApunte);
    QString toString() const;
    void responder(QString termino);
private:
    bool m_correcto;
    bool m_respuesta;
    Apunte *m_apunte;

    //Lista de terminos
};

#endif // PREGUNTA_H
