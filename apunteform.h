#ifndef APUNTEFORM_H
#define APUNTEFORM_H

#include <QWidget>
#include <QInputDialog>
#include <QAbstractButton>
#include <QMessageBox>

#include <asignatura.h>

namespace Ui {
class ApunteForm;
}

class ApunteForm : public QWidget
{
    Q_OBJECT

public:
    explicit ApunteForm(QWidget *parent = nullptr);
    ~ApunteForm();

    QList<Asignatura *> &asignaturas();
    void setAsignaturas(QList<Asignatura *> &asignaturas);    
    void cargarAsignaturas();

signals:
    void apunteTomado(Apunte *apunte);
private slots:
    void on_cmbAsignatura_currentIndexChanged(int index);

    void on_btnAgragraAsignatura_released();

    void on_pushButton_4_released();

    void on_btnAgregarTema_released();

    void on_pushButton_6_released();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ApunteForm *ui;
    QList<Asignatura *> *m_asignaturas;
    void cargarTemas(int indice);
};

#endif // APUNTEFORM_H
