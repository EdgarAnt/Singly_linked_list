#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
template<typename T>
class Nodo{
public:
    Nodo();
    Nodo(T,T);
    ~Nodo();
    Nodo *next;
    T id;
    T nombre;
    void Eliminar_Todo_();
    void print();
    buscar_nom(T);
};
template<typename T>
    Nodo<T>::Nodo()
    { id= NULL;
    nombre=NULL;
    next=NULL;
}
template<typename T>
    Nodo<T>::Nodo(T id_,T nombre_ )
{
    id=id_;
    nombre=nombre_;
    next=NULL;
}
template<typename T>
    void Nodo<T>::print()
{
    cout<<"Id:"<<id<<endl;
    cout<<"Nombre:"<<nombre<<endl;
}

template<typename T>
void Nodo<T>::Eliminar_Todo_()
{
    if (next)
        next->Eliminar_Todo();
    delete this;
}

//template<typename T>
//void List<T>::Eliminar_Todo(){
//{
//    if(ptrHead==NULL)
//        cout<<"";
//    else
//    {
//        ptrHead->Eliminar_Todo_();
//        ptrHead=0;
//    }
//}

template<typename T>
    Nodo<T>::~Nodo(){}
template<class T>
class List {
        private:
        Nodo<T> *ptrHead;
        int number_nodo;
        public:
        List();
        ~List();
        void add_head(T,T);
        void add_end(T,T);
        void add_sort(T,T);
        void delete_position(int);
        void print();
        void Search(T);
        void buscar_pos(int);
        void invert();
        void buscar_nom(T);
        void Eliminar_Todo();
        void Modificar(int);
};



template<typename T>
    List<T>::List() {
    number_nodo=0;
    ptrHead=NULL; }
template<typename T>
List<T>::~List(){}
//Insertar al inicio
template<typename T>
        void List<T>::add_head(T id_,T nombre_) {
        Nodo<T> *new_nodo=new Nodo<T>(id_,nombre_);
        Nodo<T> *temp = ptrHead;
        if(!ptrHead){
        ptrHead=new_nodo;
}
else{
    new_nodo->next=ptrHead;
    ptrHead= new_nodo;
    while(temp){
    temp=temp->next;

}
}
    number_nodo++;

}

template<typename T>
void List<T>::delete_position(int pos) {
	Nodo<T> *temp=ptrHead;
	Nodo<T> *ptrTemp=temp->next;
	if(pos<1 || pos>number_nodo){
        cout<<"Ingrese una posicion valida"<<endl;
	}else if(pos==1){
        ptrHead=temp->next;
        delete temp;
        number_nodo--;
	}else{
        for(int i=2; i<=pos; i++){
            if(i==pos){
                Nodo<T>*aux=ptrTemp;
                temp->next=ptrTemp->next;
                delete aux;
                number_nodo--;
            }
            temp=temp->next;
            ptrTemp=ptrTemp->next;
        }
	}
}



template<typename T>
	void List<T>::buscar_nom(T nombre_){
    Nodo<T> *temp=ptrHead;
	int count2=0;
	while(temp){
	    if(temp->nombre==nombre_){
			cout<<"\nId-."<<temp->id<<endl;
			cout<<"Nombre-."<<temp->nombre<<endl;

			count2++;
		}
		temp=temp->next;
	}
	if(count2==0){
		cout<<"No existe el contacto\n";
	}
	cout<<"\n\n";
}

template <typename T>
    void List<T>::add_sort(T id_,T nombre_) {
    Nodo<T> *new_nodo= new Nodo<T> (id_,nombre_);
    Nodo<T> *temp=ptrHead;
    if (!ptrHead){
    ptrHead=new_nodo;
}
else{
    if(ptrHead->id==id_){
    new_nodo

    ->next=ptrHead;
    ptrHead=new_nodo;
    }
    else{
    while(temp->next!=NULL){
    temp= temp->next;

}
    new_nodo

    ->next=temp
    ->next;

    temp

    ->next=new_nodo;
}
}
number_nodo++; }
template<typename T>
    void List<T>::print() {
    Nodo<T> *temp=ptrHead;
    if(!ptrHead){
    cout<<"La Agenda esta vacia\n";

}
else{
while(temp){
    temp->print();
    cout<<"\n\n";
    temp=temp->next;

}
}
}
template<typename T>
void List<T>::Search(T id_) {
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
while(temp){
        if(temp->id==id_){
        cout<<"Encontrado en la posicion:"<<count1<<endl;
        count2++;
}
    temp=temp->next;
    count1++;
}
if(count2==0){
    cout<<"No existe el dato\n";
}
    cout<<"\n\n";
}
template<typename T>
    void List<T>::buscar_pos(int pos)
{
    int band=0;
    Nodo<T> *aux=ptrHead;
    if(number_nodo==0)
    cout<<"Agenda esta vacia\n";
else{
if(pos<number_nodo+1&&pos>0){
for(int i=1;i<pos;i++){
    cout<<"aux"<<i<<"="<<aux->id<<endl;
    aux=aux->next;
}
    cout<<"Id-."<<aux->id<<endl;
    cout<<"Nombre-."<<aux->nombre<<endl;
}
else
    cout<<"Posicion invalida\n";
}
}
template<typename T>
    void List<T>::Modificar(int pos)
{
if(ptrHead==NULL)
cout<<"La agenda esta vacia\n";
else{
if(pos>number_nodo)
    cout<<"posicion invalida\n";
else if(pos<0)
    cout<<"posicion invalida\n";
else{
    char opc;
    string cad;
    Nodo<T>* aux1=ptrHead;
    for(int i=1;i<pos;i++){
    aux1=aux1
->next;

}
do{
    cout<<"1-.Cambiar ID\n";
    cout<<"2-.Cambiar Nombre\n";
    cout<<"0-.Salir\n";
    cin.sync();
    cin>>opc;
switch(opc){
case '1':{
    getline(cin,cad);
    cout<<"Ingresa el nuevo Id\n";

    getline(cin,cad);
    aux1->id=cad;
break;
}
case '2':{
getline(cin,cad);
cout<<"Ingresa el nuevo nombre\n";

getline(cin,cad);
aux1

->nombre=cad;

break;
}
}
system("cls");
}while(opc!='0');
}
}
}
int main (int argc,char *argv[]) {
List<string> list1;
int element,dimention,pos,dat;
string id_ ,nombre_,correo_,numero_,direccion_;
char opc;
do{
    cout<<"------------------------------------------------\n";
    cout<<"\t\tMenu contactos\n";
    cout<<"------------------------------------------------\n";
    cout<<"1-.Agregar contacto\n";
    cout<<"2-.Buscar contacto.\n";
    cout<<"3-.Eliminar contacto.\n";
    cout<<"4-.Buscar por posicion\n";
    cout<<"5-.Invertir\n";
    cout<<"6-.Buscar por nombre\n";
    cout<<"7-.Imprimir datos\n";
    cout<<"8-.Modificar\n";
    cout<<"9-.Eliminar Todo\n";
    cout<<"0-.Salir..\n";
    cout<<"Seleccione un opcion\n";
do{

cin.sync();
cin>>opc;
if(opc<='0' || opc>='9'){
    cout<<"Ingresa puros numeros"<<endl;

}

}while(opc<='0'|| opc>='9');

switch (opc){
    case '1':{
    system ("CLS");
    cin.sync();

    cout<<"ID \n";

do{
    getline(cin,id_);
if(id_<="0" || id_>="9"){
    cout<<"Ingresa puros numeros"<<endl;

}
}while(id_<="0"|| id_>="9");

cout<<"Nombre \n";
    getline(cin,nombre_);
    list1.add_head(id_,nombre_);
    list1.print();
break;
}
case '2':{
getline(cin,id_);
    cout<<"Busca un elemento\n";
do{

getline(cin,id_);
if(id_<="0" || id_>="9"){
    cout<<"Ingresa puros numeros"<<endl;

}
}while(id_<="0"|| id_>="9");
    list1.Search(id_);
break;
}
case '3':{
    cout<<"Elimina posicion\n";
    cin>>pos;
    list1.print();
break;
}
case '4':{
    cout<<"Ingresa la posicion que quieres buscar\n";
    cin.sync();
    cin>>element;
    list1.buscar_pos(element);
break;
}

case 6:{
    cout<<"Ingrese el nombre\n";
    cin>>nombre_;
    list1.buscar_nom(nombre_);
break;
}
case '7':{
        list1.print();
break;
}
case '8':{
    cout<<"Ingresa la posicion del dato a modificar\n";
    cin.sync();
    cin>>dat;
    list1.Modificar(dat);
break;
}
case '9':{
//    list1.Eliminar_Todo();
list1.print();
    break;
    }
case 0:{
    break;
    }
    }
    cout<<endl;
    system("pause");
    system("cls");
}while(opc!=0);
return 0;
}
