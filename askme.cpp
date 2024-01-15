#include "askme.h"
#include "ui_askme.h"

Askme::Askme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Askme)
{
    ui->setupUi(this);
    //cargarDatos();
    cargar();
    guardar();
    connect(ui->actionCargar, SIGNAL(released()), this, SLOT(on_actionCargar_triggered()));
}

Askme::~Askme()
{
    delete ui;
}

void Askme::on_apunteTomado(Apunte *apunte)
{
    foreach(Asignatura *a, m_asignaturas)
    {
        qDebug().noquote() << a->toString();
    }
    guardar();
    cargar();
}

void Askme::cargarSubVentana(QWidget *ventana)
{
    auto sub = ui->mdiArea->addSubWindow(ventana);
    sub->show();
}

void Askme::guardar()
{
    QFile file("apuntes.csv");
    qDebug() << "Intentando abrir el archivo para escribir...";
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Archivo abierto correctamente.";
        QTextStream salida(&file);
        salida << "Asignatura\tTema\tTermino\tConcepto\n";
        foreach(Asignatura *a, m_asignaturas)
        {
            QString nombreAsignatura = a->nombre();
            foreach(Tema *t, a->temas())
            {
                QString nombreTema = t->nombre();
                foreach (Apunte *ap, t->apuntes())  // Cambié el nombre a 'ap'
                {
                    QString termino = ap->termino();  // Cambié el nombre a 'ap'
                    QString concepto = ap->concepto();  // Cambié el nombre a 'ap'

                    salida << nombreAsignatura << "\t" << nombreTema << "\t" << termino << "\t" << concepto << "\n";
                }
            }
        }
        file.close();
        qDebug() << "Archivo cerrado correctamente.";
    }
    else
    {
        QMessageBox::critical(this, "Agregar apunte", "No se pudieron guardar los datos");
        qDebug() << "Error al abrir el archivo para escribir.";
    }
}

void Askme::cargar()
{
    QFile file("apuntes.csv");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream entrada(&file);
        entrada.readLine();
        while(!entrada.atEnd())
        {
            QString linea = entrada.readLine();
            QStringList datos = linea.split("\t");
            if(datos.size() >= 4)
            {
                QString nombreAsignatura = datos[0].trimmed();
                QString nombreTema = datos[1].trimmed();
                QString termino = datos[2].trimmed();
                QString concepto = datos[3].trimmed();
                Asignatura *asignatura = nullptr;
                Tema *tema = nullptr;


                foreach(Asignatura *a, m_asignaturas)
                {
                    if(a->nombre() == nombreAsignatura)
                    {
                        asignatura = a;
                        foreach(Tema *t, a->temas())
                        {
                            if(t->nombre() == nombreTema)
                            {
                                tema = t;
                                break;
                            }
                        }
                        break;
                    }
                }
                if (!asignatura)
                {
                    asignatura = new Asignatura(nombreAsignatura);
                    m_asignaturas.append(asignatura);
                }
                if (!tema)
                {
                    tema = new Tema(nombreTema);
                    asignatura->agregarTema(tema);
                }
                Apunte *apunte = new Apunte(termino, concepto);
                tema->agregarApunte(apunte);
            }
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Cargar datos", "No se pudieron cargar los datos");
    }
}

void Askme::on_actionNuevo_triggered()
{
    ApunteForm *w = new ApunteForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();
    connect(w, SIGNAL(apunteTomado(Apunte*)), this, SLOT(on_apunteTomado(Apunte*)));
    cargarSubVentana(w);


}


void Askme::on_actionCargar_triggered()
{
    cargar();
    QMessageBox::information(this, "Cargar datos", "Datos cargados correctamente.");
}


void Askme::on_actionLista_triggered()
{
        listaForm *w = new listaForm(this);
        cargarSubVentana(w);
        w->show();


}

