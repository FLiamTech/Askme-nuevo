#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <tema.h>

class Asignatura
{
public:
    Asignatura();
    Asignatura(const QString &nombre);

    const QList <Tema *> &temas() const;
    void agregarTema(Tema *t);
    const QString toString() const;
    QString nombre() const;

private:
    QString m_nombre;
    QList<Tema *> m_temas;
};

#endif // ASIGNATURA_H
