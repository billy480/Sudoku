#ifndef LEVEL_H
#define LEVEL_H
#include <QObject>
#include <QVector>


class level: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentlevel READ getcurrentlevel WRITE setCurrentlevel NOTIFY levelChanged FINAL)
    Q_PROPERTY(QVector<int> board READ getBoard NOTIFY boardChanged)
public:
    explicit level(QObject*parent=nullptr);
    ~level();

    Q_INVOKABLE int getcurrentlevel() const;
    Q_INVOKABLE void setCurrentlevel(int level);

    Q_INVOKABLE QVector<int> getBoard()const;


signals:
    void levelChanged();
    void boardChanged();

public slots:
    void loadlevel(int level);

private:
    int currentlevel;
    int* board;
    void generateBoard(int level);
};

#endif // LEVEL_H
