#include "pregunta.h"

Pregunta::Pregunta()
{

}

bool Pregunta::correcto() const
{
    return m_correcto;
}

bool Pregunta::respuesta() const
{
    return m_respuesta;
}

void Pregunta::setCorrecto(bool newCorrecto)
{
    m_correcto = newCorrecto;
}

void Pregunta::setRespuesta(bool newRespuesta)
{
    m_respuesta = newRespuesta;
}

Apunte *Pregunta::apunte() const
{
    return m_apunte;
}

void Pregunta::setApunte(Apunte *newApunte)
{
    m_apunte = newApunte;
}

QString Pregunta::toString() const
{
    QString str = m_apunte->toString();
    str += ", Correcta: " + QString::number(m_correcto) + ", ";
    str += "Respondida: " + QString::number(m_respuesta) + "\n";
    return str;
}

void Pregunta::responder(QString termino)
{
    m_correcto = (termino == apunte()->termino());
    m_respuesta = true;
}

Pregunta::Pregunta(Apunte *apunte) : m_apunte(apunte)
{
    m_correcto = false;
    m_respuesta = false;
}
