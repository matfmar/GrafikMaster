
#include "tworker.h"
#include "dto.h"

TWorker::TWorker(XGrafik* g, QObject* parent)
    : QObject(parent) {
    grafikBazowy = g;

}

