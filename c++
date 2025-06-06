#include <iostream>     // std::cout, std::cin
#include <string>       // std::string, std::getline

/*************************************************************
 *  Hjælpefunktioner
 *************************************************************/

// Gør ét tegn til lille bogstav hvis det er A-Z
char toLowerAZ(char ch)
{
    if (ch >= 'A' && ch <= 'Z')            // store ASCII-bogstaver
        return ch + ('a' - 'A');           // flyt 32 ned i tabellen
    return ch;                             // ellers uændret
}

// Udskriv alfabetisk frekvensliste
void printFrequencies(const int frekvens[26])
{
    std::cout << "\n­­­­Bogstav  Antal\n";
    for (int i = 0; i < 26; ++i)
        if (frekvens[i] > 0)               // spring 0-forekomster over
            std::cout << static_cast<char>('a' + i)
                      << "        " << frekvens[i] << '\n';
}

/*************************************************************
 *  Hovedprogram
 *************************************************************/

int main()
{
    /* -------------------------------------------------------
       1) Læs en hel linje fra brugeren
       ------------------------------------------------------- */
    std::cout << "Indtast en tekstlinje:\n> ";
    std::string tekst;
    std::getline(std::cin, tekst);         // snup evt. mellemrum med

    /* -------------------------------------------------------
       2–3) Fjern mellemrum, gør småt og tæl forekomster
       ------------------------------------------------------- */
    int frekvens[26] = {0};                // array med 26 heltal, init. til 0
    int bogstavTæller = 0;                 // samlet antal bogstaver

    for (size_t i = 0; i < tekst.size(); ++i)
    {
        char ch = toLowerAZ(tekst[i]);     // gør lille hvis A-Z

        // Er det nu et bogstav a-z?
        if (ch >= 'a' && ch <= 'z')
        {
            ++frekvens[ch - 'a'];          // brug forskellen som indeks (0-25)
            ++bogstavTæller;               // step samlet optælling
        }
    }

    /* -------------------------------------------------------
       4) Find mest brugte bogstav
       ------------------------------------------------------- */
    int maxIndeks = 0;                     // antag 'a' er mest brugt til at starte med
    for (int i = 1; i < 26; ++i)
        if (frekvens[i] > frekvens[maxIndeks])
            maxIndeks = i;

    /* -------------------------------------------------------
       5) Udskriv resultater
       ------------------------------------------------------- */
    std::cout << "\nAntal bogstaver (uden mellemrum): " << bogstavTæller << '\n';
    std::cout << "Mest brugte bogstav: "
              << static_cast<char>('a' + maxIndeks)
              << " (" << frekvens[maxIndeks] << " gange)\n";

    printFrequencies(frekvens);            // alfabetisk liste

    return 0;
}
