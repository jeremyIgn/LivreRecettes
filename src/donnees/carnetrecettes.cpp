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

    // No longer care for the file change
    disconnect(carnetRecettes[position], &Recette::RecetteChange, this, 0);

    carnetRecettes.removeAt(position);

    // Reconnect to good positions
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




