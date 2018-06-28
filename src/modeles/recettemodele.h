#ifndef RECETTEMODELE_H
#define RECETTEMODELE_H
#include <QAbstractListModel>
#include <QFile>
#include <QJsonDocument>
#include "../donnees/carnetrecettes.h"
#include <QStandardPaths>


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
        ImageRole, //Non utilisé
        RecetteRole
    };
    RecetteModele(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole) override;
    CarnetRecettes *recettes() const;
    void setRecettes(CarnetRecettes *carnet);
    void ajouterRecette(Recette *recette);

    void ecrireJson(QJsonObject &json) const;
    void lireJson(const QJsonObject &json);

    Q_INVOKABLE void ajouterRecette();
    Q_INVOKABLE void supprimerRecette(int row);
    bool charger();
    Q_INVOKABLE bool sauvegarder();



protected:
    QHash<int,QByteArray> roleNames() const;
private:

};

#endif // RECETTEMODELE_H
