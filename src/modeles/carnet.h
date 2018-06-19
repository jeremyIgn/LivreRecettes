#ifndef CARNET_H
#define CARNET_H

#include <QObject>
#include "../donnees/recette.h";

class Carnet : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Recette*> mesRecettes READ MesRecettes NOTIFY MesRecettesChange)
public:
    explicit Carnet(QObject *parent = nullptr);
    QList<Recette*> MesRecettes() const;

private:
    QList<Recette*> mesRecettes;

signals:

    void MesRecettesChange(QList<Recette*> value);
public slots:
};

#endif // CARNET_H
