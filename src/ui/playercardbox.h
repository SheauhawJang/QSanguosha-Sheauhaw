/********************************************************************
    Copyright (c) 2013-2015 - Mogara

    This file is part of QSanguosha-Hegemony.

    This game is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 3.0
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    See the LICENSE file for more details.

    Mogara
    *********************************************************************/

#ifndef PLAYERCARDBOX_H
#define PLAYERCARDBOX_H

#include "graphicsbox.h"
#include "card.h"
#include "player.h"

class Button;
class ClientPlayer;
class QGraphicsProxyWidget;
class QSanCommandProgressBar;

class PlayerCardBox : public GraphicsBox
{
    Q_OBJECT

public:
    explicit PlayerCardBox();

    void chooseCard(const QString &reason, const ClientPlayer *player,
        const QString &flags = "hej", bool handcardVisible = false,
        Card::HandlingMethod method = Card::MethodNone,
        const QList<int> &disabledIds = QList<int>(), const QList<int> &handcards = QList<int>(), int min_num = 0, int max_num = 0);
    void clear();

protected:
    // GraphicsBox interface
    QRectF boundingRect() const;
    void paintLayout(QPainter *painter);

private:
    void paintArea(const QString &name, QPainter *painter);
    int getRowCount(const int &cardNumber) const;
    void updateNumbers(const int &cardNumber);
    void arrangeCards(const CardList &cards, const QPoint &topLeft);

    const ClientPlayer *player;
    QString reason, flags;
    bool single_result, handcardVisible;
    Card::HandlingMethod method;
    QList<int> disabledIds;
	int min_num, max_num;
    QList<CardItem *> items, selected;

    Button *confirm;
    QGraphicsProxyWidget *progressBarItem;
    QSanCommandProgressBar *progressBar;

    QList<QRect> nameRects;

    int rowCount;
    int intervalsBetweenAreas;
    int intervalsBetweenRows;
    int maxCardsInOneRow;
    QList<int> handcards;

    static const int maxCardNumberInOneRow;

    static const int verticalBlankWidth;
    static const int placeNameAreaWidth;
    static const int intervalBetweenNameAndCard;
    static const int topBlankWidth;
    static const int bottomBlankWidth;
    static const int intervalBetweenAreas;
    static const int intervalBetweenRows;
    static const int intervalBetweenCards;

public slots:
	void selectCardItem();
    void reply();
	void reply2();
};

#endif // PLAYERCARDBOX_H
