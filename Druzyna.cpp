#include "Druzyna.h"
#include <iostream>
#include <iomanip>

Druzyna::Druzyna(int id, string nazwa, int sila)
    : id(id), nazwa(nazwa), sila(sila), punkty(0) {}

string Druzyna::getNazwa() const {
    return nazwa;
}

int Druzyna::getSila() const {
    return sila;
}

int Druzyna::getPunkty() const {
    return punkty;
}

int Druzyna::getID() const {
    return id;
}

void Druzyna::dodajPunkty(int p) {
    punkty += p;
}

void Druzyna::wyswietlDane() const {
    cout << left
        << setw(3) << id << ". "
        << setw(20) << nazwa
        << setw(10) << sila
        << setw(10) << punkty
        << endl;
}

