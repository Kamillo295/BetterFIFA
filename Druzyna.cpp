#include "Druzyna.h"
#include <iostream>
#include <iomanip>

Druzyna::Druzyna(int id, string nazwa, int sila)
    : id(id), nazwa(nazwa), sila(sila), punkty(0), bramki(0), bilansBramek(0) {}

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

int Druzyna::getBramki() const {
    return bramki;
}

void Druzyna::dodajPunkty(int p) {
    punkty += p;
}

void Druzyna::dodajBramke(int b) {
    bramki += b;
}

void Druzyna::aktualizujBilansBramek(int bil) {
    bilansBramek += bil;
}

void Druzyna::aktualizujID(int noweID) {
    id = noweID;
}

int Druzyna::getBilans() const {
    return bilansBramek;
}

void Druzyna::zerowanieBramek() {
    bramki = 0;
}

void Druzyna::wyswietlDane() const {
    cout << left
        << setw(5) << id
        << setw(20) << nazwa
        << setw(10) << sila
        << setw(10) << punkty
        << setw(10) << bilansBramek
        << endl;
}

