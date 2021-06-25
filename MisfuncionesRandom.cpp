#include "MisfuncionesRandom.h"

const string Toolbox::anuncios[] = { "turbulencias","fallo en el motor", "todo normal" };
const string Toolbox::dolor[] = { "paro cardiaco","nauseas","jaquecas","sintomas de covid-19", "mareos" };
const string Toolbox::preguntas[] = { "Que hora es", "cuanto falta","como prendo la tele","hay wifi","me podes traer otra manta, por favor","cual es la temperatura en el destino" };
const string Toolbox::respuestas[] = { relojito(), to_string(rand() % 10),"Hay un control remoto debajo del asiento","SI","SI, por supuesto",to_string(rand() % 30) };
const string Toolbox::bebidas[] = { "coca-cola", "sprite","agua sin gas", "agua con gas","jugo de naranja","cafe","te" , "vino","cerveza","champagne","whiskey" };
const string Toolbox::comidas[] = { "pasta","torta","salads","sandwiches","soups","stews","cereals","seafood","desserts","noodles" };
const string Toolbox::nombresyapellidos[] = { "Kylie Austin","Mannix Guy","Mia Ramsey","Aidan Church","Nomlanga Parsons","Malcolm Johnson","Cadman Hicks","Alice Tran","Amery Washington","Lee Frazier","Bert Zimmerman","Cooper Vincent","Lillian Torres","Vernon Chang","Keely Jordan","Danielle Walton","Hadassah Watson","Brenden Shields","Leonard Cohen","Tanisha Blanchard","April Pena","Walker King","Robert Allison","Solomon Waller","Ethan Carney","Sacha Newman","Cassady Fleming","Seth Wiley","Bernard Morgan","Ginger Harrington","Preston Cabrera","Tate Stone","Theodore Wooten","Lila Mann","Shaine Franks","Gwendolyn Pitts","Lunea Valdez","Brielle Summers","Luke Bailey","Holly Randolph","Connor Simmons","Reuben Ball","Sean Sykes","Micah Franks","Kevin Rogers","Bertha Mcdonald","Sean Madden","Keefe Robinson","Charissa House","Nash Greer","Elijah Huffman","Tara Marquez","Kylynn Vasquez","Naida Hodges","Hop Tyler","Cecilia Martinez","Ali Hansen","Salvador Mcintosh","Jerome Kirk","Iona Kemp","Perry Kramer","Autumn Brady","Erica Lowe","Travis West","MacKensie Rivera","Dorian Moore","Catherine Frye","Wynter Gardner","Whitney Wilkinson","Oleg Livingston","Sloane Ewing","Jolie Thompson","Mercedes Levine","Allegra Green","Ocean Bennett","Rahim Cash","Amethyst Britt","Blair Pacheco","Daniel Reed","Denise Oneal","Charity Maddox","Thor Powers","Natalie Coleman","Alfonso Duffy","Harper Gibson","Freya Berg","Graham Pope","September Luna","Boris Hester","Maggy Burton","Melvin Lynn","Talon Mayer","Macaulay Garrett","Petra Walsh","Bernard Curry","Tucker Harvey","Ivana Robles","Barrett Melendez","Donna Frederick","Kiona Humphrey" };
const string Toolbox::profesiones[] = { "Advertising","Tech Support","Tech Support","Payroll","Advertising","Tech Support","Research and Development","Quality Assurance","Legal Department","Customer Relations","Finances","Human Resources","Accounting","Research and Development","Human Resources","Research and Development","Tech Support","Sales and Marketing","Doctor","Nurse", "Chef", "police" };

void shuffle(int* array,int n)
{
	int a =n;
	while (a > 1)
	{
		a--;
		int i = rand() % a + 1;
		int temp = array[i];
		array[i] = array[a];
		array[a] = temp;
	}

}

string relojito()
{
	time_t t = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo ,&t);
	string mi_hora;
	mi_hora = to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	return mi_hora;
}
string mi_dni()
{
	srand(time(NULL));
	int dni = rand() % (int)(powf(10, 8) - powf(10, 7)) + powf(10, 7);
	string mi_dni1 = to_string(dni);
	return mi_dni1;
}



