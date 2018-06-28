#ifndef RECETTE_H
#define RECETTE_H

#include <QObject>
#include <QJsonObject>
class Recette : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Nom READ Nom WRITE SetNom NOTIFY NomChange)
    Q_PROPERTY(int Temps READ Temps WRITE SetTemps NOTIFY TempsChange)
    Q_PROPERTY(int NombrePersonne READ NombrePersonne WRITE SetNombrePersonne NOTIFY NombrePersonneChange)
    Q_PROPERTY(double Note READ Note WRITE SetNote NOTIFY NoteChange)
    Q_PROPERTY(QString Description READ Description WRITE SetDescription NOTIFY DescriptionChange)
    Q_PROPERTY(QString Image READ Image WRITE SetImage NOTIFY ImageChange) //Non utilisé
public:
    explicit Recette(QString nom, QObject *parent = nullptr);
    explicit Recette(QObject *parent = nullptr);
    QString Description() const;
    double Note() const;
    QString Nom() const;
    int Temps() const;
    int NombrePersonne() const;
    QString Image() const; //Non utilisé
    void lireJson(const QJsonObject &json);
    void ecrireJson(QJsonObject &json) const;
private:
    QString nom;
    int temps;
    int nombrePersonne;
    double note;
    QString description;
    QString image; //Non utilisé
signals:

    void NomChange(QString value);
    void TempsChange(int value);
    void NombrePersonneChange(int value);
    void NoteChange(double value);
    void DescriptionChange(QString value);
    void ImageChange(QString value); //Non utilisé
    void RecetteChange();

public slots:

    void SetNom(QString value);
    void SetTemps(int value);
    void SetNombrePersonne(int value);
    void SetNote(double value);
    void SetDescription(QString value);
    void SetImage(QString value); //Non utilisé
};

#endif // RECETTE_H
