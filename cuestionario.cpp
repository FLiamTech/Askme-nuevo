#include "cuestionario.h"

Cuestionario::Cuestionario()
{

}

Cuestionario::Cuestionario(Tema *tema) : m_tema(tema)
{
    foreach(Apunte *a, m_tema->apuntes())
    {
        m_preguntas.append(new Pregunta(a));
        m_terminos.append(a->termino());
    }
}

Pregunta *Cuestionario::siguiente()
{
    // TO do lanzar preguntas al azar
    foreach(Pregunta *p, m_preguntas)
    {
        if(!p->respuesta())
        {
            return p;
        }
    }
    return nullptr;
}

const QStringList &Cuestionario::terminos() const
{
    return m_terminos;
}

float Cuestionario::finalizar()
{
    int correcta = 0;
    int respondida = 0;
    foreach(Pregunta *p, m_preguntas)
    {
        if(p->respuesta())
        {
            respondida++;
            if(p->correcto())
            {
                correcta++;
            }
        }
    }
    if(respondida > 0)
    {
        return m_score = (correcta * 100.0) / respondida;
    }
    else
    {
        return m_score = 0;
    }

}

float Cuestionario::score() const
{
    return m_score;
}

const QList<Pregunta *> &Cuestionario::preguntas() const
{
    return m_preguntas;
}
