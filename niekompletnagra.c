#include<windows.h>
#include<conio.h>
#include<iostream>
#include<time.h>

using namespace std;

int czas;
int czas_koniec;
int ok;
int nr_los;
int punkty = 0;
int ruchy = 0;
char key;
char mapa[ 25 ];
int character = 13;

void tworzenie_mapy()
{
    for( int petla01 = 0; petla01 < 25; petla01 += 1 )
    {
        mapa[ petla01 ] = 32;
    };
    mapa[ character ] = 'O';
}

void ruch()
{
    if( key == 'a' )
    {
        mapa[ character ] = 32;
        if( mapa[ character - 1 ] == '*' )
        {
            punkty += 1;
        };
        character -= 1;
        mapa[ character ] = 'O';
    }
    else if( key == 'w' )
    {
        mapa[ character ] = 32;
        if( mapa[ character - 5 ] == '*' )
        {
            punkty += 1;
        };
        
        character -= 5;
        mapa[ character ] = 'O';
    }
    else if( key == 'd' )
    {
        mapa[ character ] = 32;
        if( mapa[ character + 1 ] == '*' )
        {
            punkty += 1;
        };
        
        character += 1;
        mapa[ character ] = 'O';
    }
    else if( key == 's' )
    {
        mapa[ character ] = 32;
        if( mapa[ character + 5 ] == '*' )
        {
            punkty += 1;
        };
        
        character += 5;
        mapa[ character ] = 'O';
    };
}

void los_ele()
{
    time_t t;
    srand(( unsigned ) time( & t ) );
    nr_los = rand() % 24 + 1;
    if( nr_los != character )
    {
        ok = 1;
    }
}

void element()
{
    mapa[ nr_los ] = '*';
}

void odliczanie()
{
    czas = clock() / 1000;
    czas_koniec = 60 - czas;
}

int main()
{
    cout << "Rozpocznij grê klikaj¹c dowolny klawisz .." << endl;
    getch();
    czas_koniec = 60;
    tworzenie_mapy();
    do
    {
        ok = 0;
        system( "cls" );
        cout << "Punkty: " << punkty << endl;
        cout << char( 201 ) << char( 205 ) << char( 205 ) << char( 205 ) << char( 205 ) << char( 205 ) << char( 187 ) << endl;
        cout << char( 186 ) << mapa[ 1 ] << mapa[ 2 ] << mapa[ 3 ] << mapa[ 4 ] << mapa[ 5 ] << char( 186 ) << endl;
        cout << char( 186 ) << mapa[ 6 ] << mapa[ 7 ] << mapa[ 8 ] << mapa[ 9 ] << mapa[ 10 ] << char( 186 ) << endl;
        cout << char( 186 ) << mapa[ 11 ] << mapa[ 12 ] << mapa[ 13 ] << mapa[ 14 ] << mapa[ 15 ] << char( 186 ) << endl;
        cout << char( 186 ) << mapa[ 16 ] << mapa[ 17 ] << mapa[ 18 ] << mapa[ 19 ] << mapa[ 20 ] << char( 186 ) << endl;
        cout << char( 186 ) << mapa[ 21 ] << mapa[ 22 ] << mapa[ 23 ] << mapa[ 24 ] << mapa[ 25 ] << char( 186 ) << endl;
        cout << char( 200 ) << char( 205 ) << char( 205 ) << char( 205 ) << char( 205 ) << char( 205 ) << char( 188 ) << endl;
        cout << "Pozostalo Ci Sekund.. : " << czas_koniec << endl;
        cout << "Wykonane Ruchy: " << ruchy << endl;
        cout << "ESC wychodzi z programu..." << endl;
        if( kbhit() )
        {
            key = getch();
            ruch();
            ruchy += 1;
        }
        do
        {
            los_ele();
        } while( ok != 1 );
        
        element();
        odliczanie();
    } while( czas_koniec != 0 );
    
    system( "cls" );
    cout << "Zdobyles " << punkty;
    if( punkty == 1 )
    {
        cout << " punkt .." << endl;
    }
    else if( punkty == 0 )
    {
        cout << " punktow .." << endl;
    }
    else if( 1 < punkty <= 4 )
    {
        cout << " punkty .." << endl;
    }
    else if( punkty > 4 )
    {
        cout << " punktow .." << endl;
    };
    cout << "Wcisnij klawisz aby wyjsc .." << endl;
    getch();
    exit( 0 );
}