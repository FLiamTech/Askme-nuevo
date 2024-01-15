#ifndef LISTAFORM_H
#define LISTAFORM_H

#include <QWidget>

#include<asignatura.h>

namespace Ui {
class listaForm;
}

class listaForm : public QWidget
{
    Q_OBJECT

public:
    explicit listaForm(QWidget *parent = nullptr);
    void setAsignaturas(QList<Asignatura*> &asignaturas);

    ~listaForm();


private slots:
    void on_cmbAsignaturas_currentIndexChanged(int index);

private:
    Ui::listaForm *ui;
    QList<Asignatura *> *m_asignaturas;
};

#endif // LISTAFORM_H
