#include "recette.h"

Recette::Recette(QString nom, QObject *parent) : QObject(parent), nom(nom)
{
    connect(this, &Recette::NomChange, this, &Recette::RecetteChange);
    connect(this, &Recette::TempsChange, this ,&Recette::RecetteChange);
    connect(this, &Recette::NoteChange, this ,&Recette::RecetteChange);
    connect(this, &Recette::NombrePersonneChange, this ,&Recette::RecetteChange);
    connect(this, &Recette::ImageChange, this ,&Recette::RecetteChange);
    connect(this, &Recette::DescriptionChange, this ,&Recette::RecetteChange);
}

Recette::Recette(QObject *parent) : QObject(parent)
{

}


QString Recette::Description() const
{
    return description;
}

double Recette::Note() const
{
    return note;
}

QString Recette::Nom() const
{
    return nom;
}

int Recette::Temps() const
{
    return temps;
}

int Recette::NombrePersonne() const
{
    return nombrePersonne;
}

QString Recette::Image() const
{
    return image;
}

void Recette::lireJson(const QJsonObject &json)
{
    SetNom(json["nom"].toString());
    SetTemps(json["temps"].toInt());
    SetNombrePersonne(json["nombrePersonne"].toInt());
    SetNote(json["note"].toDouble());
    SetDescription(json["description"].toString());
}

void Recette::ecrireJson(QJsonObject &json) const
{
    json["nom"] = Nom();
    json["temps"] = Temps();
    json["nombrePersonne"] = NombrePersonne();
    json["note"] = Note();
    json["description"] = Description();

}

void Recette::SetNom(QString value)
{
    if (nom != value){
        nom = value;
        emit NomChange(nom);
    }
}

void Recette::SetTemps(int value)
{
    if (temps != value){
        temps = value;
        emit TempsChange(temps);
    }
}

void Recette::SetNombrePersonne(int value)
{
    if (nombrePersonne != value){
        nombrePersonne = value;
        emit NombrePersonneChange(nombrePersonne);
    }
}

void Recette::SetNote(double value)
{
    if (note != value){
        note = value;
        emit NoteChange(note);
    }
}

void Recette::SetDescription(QString value)
{
    if (description!= value){
        description = value;
        emit DescriptionChange(description);
    }
}

void Recette::SetImage(QString value)
{
    if (image != value){
        image= value;
        emit ImageChange(image);
    }
}
