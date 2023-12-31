INSTRUKCJA OBSŁUGI DLA PROGRAMU GRAFIK MASTER v1.0

Autor programu: Mateusz Marzec SoftTech

1. LICENCE
Program Grafik Master jest rozpowszechniany zgodnie z zasadami licencji GNU GPL.

2. DISCLAIMER
Z programu korzystasz na własną odpowiedzialność. Autor programu ani nikt inny związany z jego produkcją lub rozpowszechnianiem nie odpowiada za skutki - pozytywne bądź negatywne - korzystania z tego programu.

3. PODSTAWOWE ZASADY
 a) Jeśli pole programu wymaga podania dni, należy je podać w liczbach arabskich po przecinku i bez żadnych spacji ani innych znaków.
 b) W sytuacji gdy lekarz dyżurny bierze w danym tygodniu piątek i niedzielę, liczy się to do liczby "weekendów razem z piątkami" podwójnie.

4. JAK OBSŁUGIWAĆ PROGRAM
Po uruchomieniu programu należy najpierw kliknąć pierwszy przycisk od góry, aby stworzyć bazę lekarzy dyżurnych, których będziesz używać do tworzenia grafików.

Aby stworzyć nowy grafik, należy kliknąć drugi przycisk od góry. W wyświetlonym oknie należy uzupełnić podane pola. Jest możliwe i zalecane zapisanie tych ustawień (przez kliknięcie w odpowiedni przycisk) celem późniejszego ich łatwego wczytania, jeśli będziesz chciał/a ponownie stworzyć grafik/i dla danego miesiąca i roku.

Po uzupełnieniu danych, w następnym oknie należy dodać lekarzy dyżurnych, których chcesz uwzględnić w tworzonym grafiku oraz określić ich wymagania i uzupełnić inne parametry dotyczące samego procesu tworzenia grafiku. Aby dodać lekarzy dyżurnych, zaznaczasz odpowiednią pozycję w lewym oknie, a następnie klikasz przycisk ze strzałkami w prawo, aby przenieść go do prawego okna. TAK - lekarze dyżurni w prawym oknie to lekarze, z jakich "zbudujesz" grafik. Następnie klikasz każdego z lekarzy W PRAWYM OKNIE z osobna oraz uzupełniasz pola pod oknem, które określają jego specyficzne dyżurowe pragnienia. Po uzupełnieniu NALEŻY kliknąć przycisk aktualizacji danych (u góry po środku). Kliknięcie w innego lekarza bez naciśnięcia przycisku aktualizacji spowoduje usunięcie wszystkich wprowadzonych danych i konieczność ich uzupełniania od początku. Po uzupełnieniu danych wszystkich dyżurantów zaleca się zapisanie ustawień przez kliknięcie odpowiedniego przycisku. To umożliwi ich późniejsze wczytanie bez konieczności ponownego mozolnego uzupełniania w razie sytuacji tworzenia grafiku ponownie. Następnie należy przejść pól po prawej stronie okna - jest to najciekawsza część programu, ale aby ją zrozumieć, najpierw zapraszam do przeczytania punktu nr 4.

5. JAK DZIAŁA PROGRAM.
Mechanika programu jest fuzją dwóch sposobów tworzenia algorytmów: algorytmiki z powrotami (tzw. backtracking) oraz programowania dynamicznego. Program tworzy grafik od dnia pierwszego do ostatniego, wybierając dyżurantów z pośród możliwych do wyboru dla danego dnia zasadniczo losowo; po określeniu danego dnia następuje ewentualna modyfikacja dni następnych (np. wykluczenie możliwości dodania tego samego lekarza na dzień następny). W sytuacji gdy w danym dniu nie będzie możliwe dodanie żadnego dyżuranta, algorytm wraca do dnia poprzedniego, zmieniając lekarza i ponownie próbując ustawić dzień kolejny. Tworzenie jest opatrzone na każdym kroku sprawdzaniem rozmaitych warunków zgodnie z wprowadzonymi ustawieniami, wymuszając w razie potrzeby powrót do dnia poprzedniego, jeśli jakiś warunek nie został spełniony. To wszystko oznacza, że złożoność obliczeniowa algorytmu zdefiniowana dla celu stworzenia wszystkich możliwych grafików dla danych wymagań jest odwrotnie zależna od liczby tych wymagań - mówiąc krótko, im więcej wymagań dyżurowych wszyscy nawpisywali, tym tworzenie grafików przebiegnie szybciej.
Formalnie złożoność obliczeniowa wynosi:
 a) dla przypadku najłatwiejszego O(1),
 b) dla przypadku najtrudniejszego O(n^liczba_dni_miesiąca).

W związku z punktem b) może się zdarzyć - jeśli potencjalnych dyżurantów będzie dużo a ich wymagania będą słabe - że program będzie działał bardzo długo. Podobna sytuacja może wystąpić, jeśli (użytkownik oczywiście nie jest tego świadomy), grafik zależny jest od ustawienia konkretnego dyżurnego w konkretnym dniu; wtedy - gdy program ustawi w jakiejś iteracji innego dyżurnego w tym dniu, dni następujących po tym dniu będzie dużo, a wymagania dyżurnych będą dla tych dni słabo określone - program będzie potrzebował bardzo dużo czasu, aby wrócić do tego dnia i zmienić dyżurnego. Użytkownik może te sytuacje postrzegać jako "przyblokowanie się" programu - pomimo że w sensie informatycznym program będzie działał całkowicie prawidłowo. Tą sytuację łatwo rozpoznać jako przypadek, gdy przez kilkadziesiąt sekund-kilka minut (zależnie od mocy obliczeniowej) nie zmienia się liczba ułożonych grafików. Aby poradzić sobie z tą sytuacją, program umożliwia ustawienie opcji przyspieszenia tworzenia grafików - ustawia się ją w oknie tworzenia warunków dla dyżurantów jako wybór normalna/szybka/bardzo szybka/ekstrmalnie szybka. Przyspieszenie to polega technicznie na wymuszeniu cofnięcia się przez algorytm o kilka dni wstecz, po upływie pewnego czasu (bez lub pomimo ułożenia grafików - opcja również do wyboru jako zaznaczenie). To bardzo skutecznie "odblokuje" program, ale kosztem rezygnacji z ułożenia wszystkich możliwych grafików dla danych warunków. Mimo wszystko polecam jej stosowanie.

Kod programu implementuje obsługę wątków oraz działa w oparciu o wywołania rekurencyjne. To oznacza (:)) - na szczęście jest to mało prawdopodobne - że pomimo testów przed jego wydaniem, możliwe jest jego "dziwne" zachowanie w różnych "nieprzewidzianych" sytuacjach. Wtedy zaleca się zrestartowanie programu i rozpoczęcie procesu tworzenia grafików od nowa.

6. PRZEGLĄDANIE STWORZONYCH GRAFIKÓW
Po stworzeniu grafików należy kliknąć przycisk trzeci od góry w oknie głównym programu. W nowo otwartym oknie należy uzupełnić miesiąc i rok oraz kliknąć przycisk szukania. Grafiki można przeglądać przyciskami z symbolami strzałek. Zalecane jest rozszerzenie okna do rozmiarów możliwych na monitorze użytkownika. Dany grafik można usunąć, przyklepać jako ostateczny (tylko jeden grafik z danego miesiąca i roku może zostać przyklepany jako ostateczny) oraz zapisać w formacie PDF.

7. PRZEGLĄDANIE OSTATECZNYCH GRAFIKÓW
Należy kliknąć przycisk czwarty od góry. Obsługa jest analogiczna do tej z punktu nr 5.

8. INFORMACJE KOŃCOWE
W razie wątpliwości, pytań, uwag lub chęci zgłoszenia potencjalnych lub realnych błędów proszę pisać na adres:
mateuszmarzecsofttech@protonmail.com

Miłego układania grafików !