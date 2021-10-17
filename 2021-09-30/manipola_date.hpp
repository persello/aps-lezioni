#pragma once

bool DataValida(unsigned giorno, unsigned mese, unsigned anno);
unsigned GiorniDelMese(unsigned mese, unsigned anno);
bool Bisestile(unsigned anno);
void DataSuccessiva(unsigned &giorno, unsigned &mese, unsigned &anno);
void DataPrecedente(unsigned &giorno, unsigned &mese, unsigned &anno);
