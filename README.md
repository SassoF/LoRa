# Progetto: Notifica di Blackout via LoRa e Telegram

## Descrizione

Questo progetto ha lo scopo di **inviare una notifica su Telegram quando manca la corrente elettrica** in un determinato luogo. Utilizza due dispositivi basati su **LoRa** per la comunicazione a lungo raggio tra il punto di rilevamento e il punto di notifica.

## Architettura del Sistema

Il sistema è suddiviso in due unità principali:

- **TX (Trasmettitore)**  
  Si occupa di rilevare la mancanza di corrente elettrica e inviare un messaggio via LoRa.

- **RX (Ricevitore)**  
  Riceve il messaggio LoRa dal trasmettitore e invia una notifica su Telegram.

## Funzionamento

1. Quando la corrente elettrica viene a mancare, il modulo **TX**, alimentato da una batteria si attiva.
2. TX invia un messaggio tramite LoRa al modulo **RX**.
3. Il modulo **RX**, una volta ricevuto il messaggio, utilizza una connessione Internet per **inviare un messaggio Telegram**.
4. L’utente riceve immediatamente una notifica dell’interruzione di corrente.

## Struttura delle Cartelle

Il progetto è organizzato in due cartelle principali:

- `tx/`  
  Contiene il codice per il modulo trasmettitore (rilevamento blackout e invio LoRa).

- `rx/`  
  Contiene il codice per il modulo ricevitore (ricezione LoRa e invio Telegram).

## Requisiti Hardware

- 2 Moduli compatibili con LoRa
- Alimentazione di backup per il modulo TX
- Connessione Internet per il modulo RX (Wi-Fi o altro)
- Accesso a un bot Telegram per l'invio delle notifiche

## Requisiti Software

- Librerie LoRa per i microcontrollori utilizzati
- API Bot Telegram
- Script di gestione degli eventi (presenti nelle cartelle `tx/` e `rx/`)
