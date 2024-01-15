#include "asignatura.h"

Asignatura::Asignatura()
{

}

Asignatura::Asignatura(const QString &nombre) : m_nombre(nombre)
{}

const QList<Tema *> &Asignatura::temas() const
{
    return m_temas;
}

void Asignatura::agregarTema(Tema *t)
{
    m_temas.append(t);
}

const QString Asignatura::toString() const
{
    QString str = "Asignatura: " + m_nombre + "\n";
    foreach(Tema *t, m_temas)
    {
        str += t->toString();
    }
    return str;
}

QString Asignatura::nombre() const
{
    return m_nombre;
}

