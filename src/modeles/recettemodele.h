#ifndef RECETTEMODELE_H
#define RECETTEMODELE_H
#include <QAbstractListModel>

#include "../donnees/carnetrecettes.h"


class RecetteModele : public QAbstractListModel
{
Q_OBJECT
    CarnetRecettes *monCarnet;
    Q_PROPERTY(CarnetRecettes *monCarnet READ recettes WRITE setRecettes )
public:
    enum RecetteRoles {
        NomRole = Qt::UserRole,
        TempsRole,
        NombrePersonneRole,
        NoteRole,
        DescriptionRole,
        ImageRole,
        RecetteRole
    };
    RecetteModele(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole) override;
    CarnetRecettes *recettes() const;
    void setRecettes(CarnetRecettes *carnet);
    void ajouterRecette(Recette *recette);
    Q_INVOKABLE void ajouterRecette();
    Q_INVOKABLE void supprimerRecette(int row);

protected:
    QHash<int,QByteArray> roleNames() const;
private:

};

#endif // RECETTEMODELE_H
