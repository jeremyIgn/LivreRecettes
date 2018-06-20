#ifndef CARNETRECETTES_H
#define CARNETRECETTES_H
#include <QJsonArray>
#include <QObject>
#include "recette.h"

class CarnetRecettes : public QObject
{
    Q_OBJECT
    QList<Recette*> carnetRecettes;
public:
    explicit CarnetRecettes(QObject *parent = 0);
    QList<Recette *> Carnet() const;
    void ajouterRecette(Recette *recette);
    void supprimerRecette(int position);
    int count() const;
    Recette *at(int place) const;
    void lireJson(const QJsonObject &json);
    void ecrireJson(QJsonObject &json) const;

signals:
    void CarnetChange(int row);
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

};

#endif // CARNETRECETTES_H
