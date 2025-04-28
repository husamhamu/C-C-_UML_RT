Thanks for your patience.  
Now that I see the full picture — your project included **both** the **Papyrus-RT UML modeling** **and** **C/C++ programming exercises** (from basic C++ to memory, OOP, templates, and C for embedded systems) — here is the **corrected and upgraded `README.md`** that **properly shows your technical and programming skills** across **modeling** and **implementation**:

---

# 🚛 TruckBed Control System – Modellierung, Simulation und Embedded-Programmierung (Papyrus-RT & C/C++)

> 🎓 Lab @ TU Darmstadt  
> 🛠️ Modellierung und Implementierung eines Muldensteuerungssystems in UML-RT & C/C++

---

## 🚀 Projektüberblick

In diesem Projekt wurde ein vollständiges Embedded-System entworfen, modelliert und implementiert:  
Die **Steuerung der Kippmulde eines Trucks** unter Echtzeitbedingungen.  
Dafür wurden **Papyrus-RT (UML-RT)** für die grafische Modellierung und **C/C++** für die low-level Programmierung verwendet.

🔑 **Schwerpunkte:**
- UML-RT Modellierung in Papyrus-RT 📈
- Ereignisgesteuerte Zustandsautomaten und Capsules ⚙️
- Speicherverwaltung, OOP und Templates in C++ 🔧
- C-Programmierung für embedded Systems (Memory, Bit-Operationen) 🧩
- Codegenerierung und Anbindung an einen TruckBed-Simulator 🚛

---

## 📂 Projektstruktur

```bash
📦 TruckBedControlSystem/
├── UML_Model/                # UML-RT Modelle in Papyrus-RT
├── Exercises_CPP_C/           # C++ und C Programmierübungen
│   ├── Grundlagen/            # [G] Basisübungen C++ (Funktionen, Enums)
│   ├── Speicherverwaltung/    # [S] Zeiger, Referenzen, Arrays
│   ├── Objektorientierung/    # [O] Vererbung, Polymorphie, Rule of Three
│   ├── Fortgeschritten/       # [F] Templates, Funktionale Programmierung
│   └── Embedded_C/            # [C] C Grundlagen, Bitmanipulation, Speicherverwaltung
├── Anforderungen/             # TruckBed_Anforderungen.pdf, Systembeschreibung
├── Simulation/                # Build- und Ausführungsanleitung für TruckBed-Simulator
└── README.md                  # Projektdokumentation (dieses Dokument)
```

---

## 🧠 Technische Highlights

### 📌 1. Modellierung mit UML-RT (Papyrus-RT)

- **Systemarchitektur**: Modellierung von Capsules, Ports und Protokollen für Joystick, Motor und Sensorik (vgl. Papyrus-RT Tutorial, Kapitel 2.3–2.4)
- **Zustandsautomaten**: Entwicklung ereignisbasierter Steuerungslogik (Rotation Control Statechart)
- **SimulationTop**: Verknüpfung der Hardware- und Simulationslogik in einer Top-Level-Kapsel

![image](https://github.com/user-attachments/assets/894552aa-521a-4ae9-a6b3-ad46f56f00b4)

---

### 🧩 2. C++ Grundlagen und Speicherverwaltung

- **Erstellung von Programmen**: Vom ersten "Hello World" bis hin zu komplexen Strukturierungen mit Header- und Source-Dateien
- **Pointer & Referenzen**: Direkte Speicherzugriffe, Pointerarithmetik und Funktionsübergaben
- **Dynamische Speicherverwaltung**: Nutzung von malloc/free und new/delete

---

### 🧩 3. Objektorientierte Programmierung (OOP)

- **Rule of Three**: Implementierung korrekter Kopierkonstruktoren, Assignment-Operatoren und Destruktoren (z.B. Klasse `Box`)
- **Vererbung und Polymorphie**: Erstellung hierarchischer Klassen (z.B. `Person`, `Student`) mit `virtual` Methoden
- **Dynamischer Dispatch**: Nutzung von virtuellen Methoden für polymorphes Verhalten

---

### 🛠️ 4. Templates und Fortgeschrittene C++-Techniken

- **Generische Programmierung**: Entwicklung template-basierter Funktionen (z.B. `maximum<T>()`) und Datenstrukturen (z.B. `Vector3<T>`)
- **Functional Programming in C++**: Implementierung von `map`, `filter` und `reduce` nach funktionalem Paradigma

---

### 🧩 5. Embedded C-Programmierung

- **Bitoperationen und Speicheroptimierung**: Anwendung von & | ~ >> << auf char/integers für Low-Level-Programmierung
- **Effiziente String- und Speicherverwaltung**: Nutzung von `printf`, `sprintf`, Heap-Speicher und char-Arrays
- **Eingeschränkte Ressourcenmodelle**: C-spezifische Herausforderungen wie manuelles Memory Management und Pointer-Sicherheit

---

## 📈 Visualisierungen & Beispiele

- 🖼️ **Capsule-Diagramm**: Modellierung der Muldenlogik im SimulationTop Modell  
- 📊 **Statechart**: Steuerung des Muldenwinkels über Rotation Control Statechart  
- 📋 **Pointer-Speicherabbild**: Analyse von Zeigern und Speicheradressen

---

## ⚙️ Technologien und Tools

| Tool / Sprache | Nutzung |
|:---------------|:--------|
| Papyrus-RT 📈 | UML-RT Modellierung, Codegenerierung |
| C++ (Clang++) 🐍 | Objektorientierte Steuerung und Speicherverwaltung |
| C (gcc) 🧩 | Embedded-nahes Programmieren |
| CodeLite 🖥️ | Entwicklungsumgebung für C/C++ |
| Oracle VirtualBox 📦 | Virtuelle Entwicklungsumgebung |

---

## 🏁 Ausführung der Simulation

1. Virtuelle Maschine importieren (`ubuntu20es.ova`)  
2. TruckBed UML-Modell (`SimulationTop`) in Papyrus-RT öffnen  
3. Code generieren und kompilieren:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./TopMain
   ```
4. TruckBed Simulator GUI starten und Verbindungen testen

---

## 📄 Quellen und Referenzen

- [TruckBed_Anforderungen.pdf](./Anforderungen/TruckBed_Anforderungen.pdf)  
- [Papyrus-RT-Tutorial.pdf](./Papyrus-RT-Tutorial.pdf)  

---

# 🎯 Zusammenfassung

Dieses Projekt demonstriert umfassende Kenntnisse in  
**Systemmodellierung, Speicherverwaltung, objektorientierter Programmierung und Embedded Systems**.  
Von der **grafischen Modellierung** bis hin zur **tiefen hardwarenahen C-Programmierung** wurde ein vollständiger Engineering-Workflow umgesetzt.

---
