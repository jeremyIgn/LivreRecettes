#ifndef RECETTE_H
#define RECETTE_H

#include <QObject>

class Recette : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Nom READ Nom WRITE SetNom NOTIFY NomChange)
    Q_PROPERTY(int Temps READ Temps WRITE SetTemps NOTIFY TempsChange)
    Q_PROPERTY(int NombrePersonne READ NombrePersonne WRITE SetNombrePersonne NOTIFY NombrePersonneChange)
    Q_PROPERTY(float Note READ Note WRITE SetNote NOTIFY NoteChange)
    Q_PROPERTY(QString Description READ Description WRITE SetDescription NOTIFY DescriptionChange)
    Q_PROPERTY(QString Image READ Image WRITE SetImage NOTIFY ImageChange)
public:
    explicit Recette(QString nom, QObject *parent = nullptr);
    QString Description() const;
    float Note() const;
    QString Nom() const;
    int Temps() const;
    int NombrePersonne() const;
    QString Image() const;

private:
    QString nom;
    int temps;
    int nombrePersonne;
    float note;
    QString description;
    QString image;
signals:

    void NomChange(QString value);
    void TempsChange(int value);
    void NombrePersonneChange(int value);
    void NoteChange(float value);
    void DescriptionChange(QString value);
    void ImageChange(QString value);
    void RecetteChange();

public slots:

    void SetNom(QString value);
    void SetTemps(int value);
    void SetNombrePersonne(int value);
    void SetNote(float value);
    void SetDescription(QString value);
    void SetImage(QString value);
};

#endif // RECETTE_H
