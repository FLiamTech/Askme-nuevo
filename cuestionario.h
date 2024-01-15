#ifndef CUESTIONARIO_H
#define CUESTIONARIO_H

#include <QString>

#include <pregunta.h>
#include <tema.h>

class Cuestionario
{
public:
    Cuestionario();
    Cuestionario(Tema *tema);
    Pregunta *siguiente();
    const QStringList &terminos() const;
    float finalizar();
    void terminar();
    float score() const;

    const QList<Pregunta *> &preguntas() const;

private:
    float m_score;
    Tema *m_tema;
    QList<Pregunta*> m_preguntas;
    QStringList m_terminos;
};

#endif // CUESTIONARIO_H
