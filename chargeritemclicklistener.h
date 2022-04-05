#ifndef CHARGERITEMCLICKLISTENER_H
#define CHARGERITEMCLICKLISTENER_H

class ChargerItemClickListener {
public:
    ChargerItemClickListener() {}
    virtual ~ChargerItemClickListener() {}
    virtual void onChargerItemClicked(unsigned int connectorId) = 0;
};

#endif // CHARGERITEMCLICKLISTENER_H
