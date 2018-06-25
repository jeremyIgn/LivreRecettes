#include "recettemodele.h"


RecetteModele::RecetteModele(QObject *parent): QAbstractListModel(parent), monCarnet(nullptr)
{
    monCarnet = new CarnetRecettes();
}


int RecetteModele::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid())
        return 0;
    return monCarnet->Carnet().count();
}

QVariant RecetteModele::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto recette = monCarnet->at(index.row());

    switch (role) {
    case NomRole:
        return recette->Nom();
    case TempsRole:
        return recette->Temps();
    case NombrePersonneRole:
        return recette->NombrePersonne();
    case NoteRole:
        return recette->Note();
    case DescriptionRole:
        return recette->Description();
    case ImageRole:
        return recette->Image();
    case RecetteRole:
        return QVariant::fromValue(recette);
    default:
        break;
    }

    return QVariant();
}

bool RecetteModele::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        Recette *recette = monCarnet->at(index.row());

        switch (role) {
        case NomRole:
            recette->SetNom(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case TempsRole:
            recette->SetTemps(value.toInt());
            emit dataChanged(index, index, QVector<int>() << role);
        case NombrePersonneRole:
            recette->SetNombrePersonne(value.toInt());
            emit dataChanged(index, index, QVector<int>() << role);
        case NoteRole:
             recette->SetNote(value.toFloat());
             emit dataChanged(index, index, QVector<int>() << role);
        case DescriptionRole:
            recette->SetDescription(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case ImageRole:
            recette->SetImage(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        default:
            break;
        }
        return true;
    }
}

CarnetRecettes *RecetteModele::recettes() const
{
    return monCarnet;
}

void RecetteModele::setRecettes(CarnetRecettes *carnet)
{

    beginResetModel();

       if (monCarnet)
           monCarnet->disconnect(this);

       monCarnet = carnet;

       if (monCarnet) {
           connect(monCarnet, &CarnetRecettes::preItemAppended, this, [=]() {
               const int index = monCarnet->count();        // Append implies end
               beginInsertRows(QModelIndex(), index, index);
           });
           connect(monCarnet, &CarnetRecettes::postItemAppended, this, [=]() {
               endInsertRows();
           });

           connect(monCarnet, &CarnetRecettes::preItemRemoved, this, [=](int index) {
               beginRemoveRows(QModelIndex(), index, index);
           });
           connect(monCarnet, &CarnetRecettes::postItemRemoved, this, [=]() {
               endRemoveRows();
           });
           connect(monCarnet, &CarnetRecettes::CarnetChange,
                   this, [=](int row){emit RecetteModele::dataChanged(this->index(row), this->index(row)); });
       }

       endResetModel();
}

void RecetteModele::ajouterRecette(Recette *recette)
{
    monCarnet->ajouterRecette(recette);
}

void RecetteModele::ecrireJson(QJsonObject &json) const
{
   monCarnet->ecrireJson(json);
}

void RecetteModele::ajouterRecette()
{
    QString name(tr("Recette"));
    monCarnet->ajouterRecette(new Recette(name));
}

void RecetteModele::supprimerRecette(int row)
{
    monCarnet->supprimerRecette(row);
}

bool RecetteModele::charger()
{
    QFile file(QString("recettes.json"));
    if (!file.open(QIODevice::ReadWrite)) {
            qWarning("Couldn't open save file.");
            return false;
    }
    QByteArray donnees = file.readAll();
    QJsonDocument document(QJsonDocument::fromJson(donnees));
    lireJson(document.object());
    return true;
}

bool RecetteModele::sauvegarder()
{
    QFile sauvegarde(QString("recettes.json"));
    if (!sauvegarde.open(QIODevice::ReadWrite)) {
            qWarning("Couldn't open save file.");
            return false;
    }
    QJsonObject carnet;
    ecrireJson(carnet);
    QJsonDocument document;
    sauvegarde.write(document.toJson());
    return true;
}

void RecetteModele::lireJson(const QJsonObject &json)
{
    monCarnet->lireJson(json);
}


QHash<int, QByteArray> RecetteModele::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[NomRole] = "Nom";
    roles[TempsRole] = "Temps";
    roles[NombrePersonneRole] = "NombrePersonne";
    roles[NoteRole] = "Note";
    roles[DescriptionRole] = "Description";
    roles[ImageRole] = "Image";
    roles[RecetteRole] = "Recette";
    return roles;
}
