#include "apunteform.h"
#include "ui_apunteform.h"

ApunteForm::ApunteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApunteForm)
{
    ui->setupUi(this);
    connect(ui->cmbAsignatura, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbAsignaturas_currentIndexChanged(int)));
}

ApunteForm::~ApunteForm()
{
    delete ui;
}

QList<Asignatura *> &ApunteForm::asignaturas()
{
    return *m_asignaturas;
}

void ApunteForm::setAsignaturas(QList<Asignatura *> &asignaturas)
{
    m_asignaturas = &asignaturas;
}

void ApunteForm::cargarAsignaturas()
{
    ui->cmbAsignatura->clear();
    foreach(Asignatura *a, *m_asignaturas)
    {
        ui->cmbAsignatura->addItem(a->nombre());
    }
}

void ApunteForm::on_cmbAsignatura_currentIndexChanged(int index)
{
    cargarTemas(index);
}

void ApunteForm::cargarTemas(int indice)
{
    ui->cmbClase->clear();
    if(indice >= 0 && indice < m_asignaturas->size())
    {
        Asignatura *a = m_asignaturas->at(indice);
        QList<Tema *> temas = a->temas();
        foreach(Tema *t, temas)
        {
            ui->cmbClase->addItem(t->nombre());
        }
    }
}

void ApunteForm::on_btnAgragraAsignatura_released()
{
    bool ok;
    QString nombre = QInputDialog::getText(this, "Agregar nueva asignatura","Nombre", QLineEdit::Normal, "", &ok);
    if(ok && !nombre.isEmpty())
    {
        m_asignaturas->append(new Asignatura(nombre));
        cargarAsignaturas();
    }
}


void ApunteForm::on_pushButton_4_released()
{
    cargarAsignaturas();
}


void ApunteForm::on_btnAgregarTema_released()
{
    bool ok;

    QString tema = QInputDialog::getText(this, "Agregar tema", "Tema", QLineEdit::Normal, "", &ok);
    if(ok)
    {
        int indiceAsignatura = ui->cmbAsignatura->currentIndex();
        Asignatura *a = m_asignaturas->at(indiceAsignatura);
        Tema *nuevoTema = new Tema(tema);
        a->agregarTema(nuevoTema);
        ui->cmbClase->addItem(tema);
    }
}


void ApunteForm::on_pushButton_6_released()
{
    cargarAsignaturas();
}


void ApunteForm::on_buttonBox_accepted()
{
    QString termino = ui->txtTermino->text();
    QString concepto = ui->textEdit->toPlainText();
    int temaIndex = ui->cmbClase->currentIndex();
    int asignaturaIndex = ui->cmbAsignatura->currentIndex();

    if (asignaturaIndex < 0)
    {
        QMessageBox::warning(this, "Agregar apunte", "No se ha seleccionado una asignatura");
        ui->cmbAsignatura->setFocus();
        return;
    }

    if (temaIndex < 0)
    {
        QMessageBox::warning(this, "Agregar apunte", "No se ha seleccionado un tema");
        ui->cmbClase->setFocus();
        return;
    }

    if (termino.isEmpty())
    {
        QMessageBox::warning(this, "Agregar apunte", "El término no puede quedar vacío");
        ui->txtTermino->setFocus();
        return;
    }

    if (concepto.isEmpty())
    {
        QMessageBox::warning(this, "Agregar apunte", "El concepto no puede quedar vacío");
        ui->textEdit->setFocus();
        return;
    }

    // Crear el nuevo apunte
    Apunte *apunte = new Apunte(termino, concepto);
    // Obtener la asignatura seleccionada
    Asignatura *a = m_asignaturas->at(asignaturaIndex);
    // Agregar el apunte al tema seleccionado
    a->temas().at(temaIndex)->agregarApunte(apunte);

    emit apunteTomado(apunte);
    this->parentWidget()->close();
}


void ApunteForm::on_buttonBox_rejected()
{
    this->parentWidget()->close();
}

