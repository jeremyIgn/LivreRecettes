#include "carnetrecettes.h"

CarnetRecettes::CarnetRecettes(QObject *parent) : QObject(parent)
{

}

QList<Recette *> CarnetRecettes::Carnet() const
{
    return carnetRecettes;

}



void CarnetRecettes::ajouterRecette(Recette *recette)
{
   emit preItemAppended();
   int position = count();
   connect(recette, &Recette::RecetteChange, this, [=](){ emit CarnetRecettes::CarnetChange(position); });
   carnetRecettes.append(recette);
   emit postItemAppended();
}

void CarnetRecettes::supprimerRecette(int position)
{
    emit preItemRemoved(position);
    disconnect(carnetRecettes[position], &Recette::RecetteChange, this, 0);
    carnetRecettes.removeAt(position);
    for ( ; position < count() ; ++position ) {
        disconnect( carnetRecettes[position], &Recette::RecetteChange, this, 0);
        connect( carnetRecettes[position], &Recette::RecetteChange, this, [=](){ emit CarnetRecettes::CarnetChange(position);});
    }
    emit postItemRemoved();
}

int CarnetRecettes::count() const
{
    return carnetRecettes.count();
}

Recette *CarnetRecettes::at(int place) const
{
    return carnetRecettes.at(place);
}

void CarnetRecettes::lireJson(const QJsonObject &json)
{

 QJsonArray recettes = json["recettes"].toArray();
 for (int index = 0; index < recettes.size(); ++index) {
     QJsonObject recette = recettes[index].toObject();
     Recette *r{};
     r->lireJson(recette);
     ajouterRecette(r);
 }
}

void CarnetRecettes::ecrireJson(QJsonObject &json) const
{
    QJsonArray recettes;
    foreach (const Recette *r, carnetRecettes) {
        QJsonObject recetteObject;
        r->ecrireJson(recetteObject);
        recettes.append(recetteObject);
    }
    json["recettes"] = recettes;
}




