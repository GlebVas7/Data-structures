//Очередь очередей целого типа.
#include <stdio.h>
#include <io.h>
#include <locale>

struct ocher {
	struct ocher2* data;
	struct ocher* next;
};

struct ocher2 {
	int  dataint;
	struct ocher2* next;
};

int o2 = 0;

void change_el_ocher1_begin(struct ocher**, struct ocher**, struct ocher2**, struct ocher2**, int*, int*);//
struct ocher2* change_el_second_ochered(struct ocher2*, struct ocher2**, struct ocher2**);//
void delete_el_ocher1_begin(ocher**, ocher**);//функция удаления элемента из начала внешней очереди
struct ocher2* delete_el_ochered_begin(struct ocher2**, struct ocher2**, struct ocher2**);//функция удаления элемента из начала внутренней очереди
void print_ocher(struct ocher2**, struct ocher2**);//фенкция печатанья внутренней очереди
void print_ocher1(ocher**, ocher**);//функция печатанья внешней очереди
struct ocher* menu_ocher2(struct ocher*, struct ocher2**, struct ocher2**, int*, int*);//функция меню работы со внутренней очередью
void take_el_ocher1_begin(struct ocher**, struct ocher**, struct ocher*);//функция взятия элемента из начала внешней очереди
struct ocher2* take_el_from_begin(struct ocher2*, struct ocher2**, struct ocher2**, int*);//функция взятия элемента из начала внутренней очереди
void show_el_ocher1(struct ocher**, struct ocher**);// функция демонстрации элемента в начале внешней очереди
void check_el_start(struct ocher2**);//функция демонстрации элемента в начале внутренней очереди
void check_ocher(struct ocher2**, struct ocher2**);//функция проверки на пустоту внутренней очереди
void check_ocher1(struct ocher**, struct ocher**);//функция проверки на пустоту внешней очереди
void add_el_ocher1_end(struct ocher**, struct ocher**, struct ocher2**, struct ocher2**, int, int*, int*, int*);//функция добавления элемента в конец внутренней очереди
struct ocher2* add_el_ocher2_end(struct ocher2**, struct ocher2**, struct ocher2**);//функция добавления элемента в конец внешней очереди
void clear_ochered1(struct ocher**, struct ocher**);// функция очистки очереди
struct ocher2* clear_ochered(struct ocher2**, struct ocher2**, struct ocher2*);// функция очистки очереди
void end_work_ochered(struct ocher**, struct ocher**);// функция окончания работы с очередью
void start_work_ochered(struct ocher**, struct ocher**);// функция начала работы с очередью



struct ocher2* change_el_second_ochered(struct ocher2* uk, struct ocher2** start2, struct ocher2** end2) {
	int cymbol;
	if (*start2 != NULL) {
		printf("Введите символ: ");
		scanf_s("%d", &cymbol);
		(*start2)->dataint = cymbol;
		printf("Очеред с измененным элементом :\n");
		print_ocher(start2, end2);
	}
	else {
		printf("Очередь пуста!\n");
	}
	uk = *start2;
	return uk;
}

void change_el_ocher1_begin(struct ocher** start, struct ocher** end, struct ocher2** start2, struct ocher2** end2,int* save, int* flag)
{
	if (*start == NULL && *end == NULL)
		printf("Очередь пуста\n");
	else
	{
		struct ocher* tmp;
		struct ocher* ptm;
		if (*start != NULL)//если в начале что-то есть
		{
			tmp = *start;//помещаем указатель на начало в вспомогательный указатель
			ptm = (*start)->next;//помещаем указатель на следующий элемент в вспомогательный указатель

			*flag = 1;// меняем флаг
			tmp = menu_ocher2(tmp, start2, end2, save, flag);//вызываем меню второй очереди
			*start = tmp;// обновляем элемент в начале
			(*start)->next = ptm;// устанавливаем связь с остальными элементами очереди
			print_ocher1(start, end);//печатаем очередь
		}
	}
}


void take_el_ocher1_begin(struct ocher** start, struct ocher** end, struct ocher* save2)//функция взятия элемента из начала первой очереди
{
	if (*start == NULL && *end == NULL)
		printf("Очередь пуста\n");
	else
	{
		save2 = *start;// сохраняем указатель на удаляемый элемент
		struct ocher* tmp;
		struct ocher2* pmt = NULL;
		if (*start != NULL)//если у нас в начале что-то есть
		{
			tmp = *start;
			pmt = tmp->data;//переходим на вторую очередь
			printf("Значение взятого из списка после рабочего указателея элемента: ");
			if (pmt)
				while (pmt)//печатаем элементы второй очереди
				{
					printf("%d ", pmt->dataint);
					pmt = pmt->next;
				}
			else// печатаем пустую очередь
				printf("0(очередь пуста)\n");
			printf("\n");

		}
		delete_el_ocher1_begin(start, end);//удаляем элемент
	}

}

struct ocher2* take_el_from_begin(struct ocher2* uk,struct ocher2** start2, struct ocher2**end2, int* save)//функция взятия элемента из начала второй очереди
{
	if (*start2 != NULL) {
		*save = (*start2)->dataint;// сохраняем удаляемый элемент
		delete_el_ochered_begin(start2, end2, &uk);// удаляем элемент
		printf("\n");
		uk = *start2;//обновляем указатель на вторую очередь 
		printf("Значение взятого из начала очереди элемента: %d \n", *save);
		//print_ocher(start2, end2);
		return uk;
	}
	else {
		printf("Очередь пуста!\n");
	}

}

void show_el_ocher1(struct ocher** start, struct ocher** end)// функция демонстрации элемента в начале первой очереди
{
	struct ocher* tmp;// вспогательный указатель на элемент первой очереди
	struct ocher2* pmt = NULL;// вспогательный указатель на вторую очередь
	if (*start == NULL && *end == NULL)// если первая очередь пуста
		printf("Очередь пуста  \n");

	if (*start != NULL)// если что-то у нас есть в начале
	{
		printf("Значение элемента в начале очереди  \n");
		
		tmp = *start;// присваиваем указатель на старт
		pmt = tmp->data;// переходим от первой очереди ко второй
		if (pmt)
			while (pmt)// пока не дошли до конца второй очереди
			{
				printf("%d ", pmt->dataint);// печатаем элементы второй очереди
				pmt = pmt->next;// передвигаемся к следующему
				
			}
		else// если вторая очередь пуста
			printf("0(очередь пуста)\n");// печатаем
		printf("\n");
		printf("\n");
		print_ocher1(start, end);// печатаем очередь
	}

}

void print_ocher1(struct ocher** start, struct ocher** end)// функция печати первой очереди
{
	struct ocher* tmp = *start;// помещаем указатель на старт очереди в новый вспомогательный указатель
	struct ocher2* pmt = NULL;//указатель на вторую очередь
	if (*start != NULL && *end != NULL)// если очередь не пуста
	{
		printf("Очередь:\n");
		while (tmp)// пока мы не дошли до конца очереди
		{
			printf("\n");
			pmt = tmp->data;// переходим с первой очереди на вторую очередь
			if (pmt)// если вторая очередь не пуста
				while (pmt)// пока не дошли до конца второй очереди
				{
					printf("%d ", pmt->dataint);// печатаем элементы второй очереди
					pmt = pmt->next;// передвигаемся по второй очереди
				}
			else// если вторая очередь пуста
				printf("0(очередь пуста)\n");
			printf("\n");
			if (tmp->next != NULL)// переходи к следующему элементу первой очереди, если мы не в конце
				tmp = tmp->next;// переходи к следующему элементу первой очереди
			else
				break;
		}

	}
	else
		printf("Очередь пуста\n");
}

void print_ocher(struct ocher2** start2, struct ocher2** end2) {
	struct ocher2* tmp;
	if (*start2 != NULL && *end2 != NULL) {
		printf("Очередь:\n");
		printf("\n");
		tmp = *start2;
		if (tmp->next == NULL) {
			printf("%d ", tmp->dataint);
		}
		while (tmp->next != NULL) {
			printf("%d ", tmp->dataint);
			tmp = tmp->next;
			if (tmp->next == NULL)// когда дошли до последнего
			{
				printf("%d ", tmp->dataint);
				*end2 = tmp;// конец второй очереди равен последнему элементу второй очереди
			}
		}
		printf("\n");
	}
	else {
		printf("Очередь пуста!\n");
	}
}

void delete_el_ocher1_begin(struct ocher** start, struct ocher** end)// функция удаления элемента из начала первой очереди
{
	struct ocher* hlpy = NULL;
	if (*start == NULL && *end == NULL)// если очередь пуста
		printf("Очередь пуста ,невозможно удалить элемент \n");
	if (*start != NULL && (*start) == (*end))// если у нас только один элемент
	{
		hlpy = *start;// помещаем указатель на этот элемент в вспомогательный указатель
		*end = NULL;// обнуляем указатели
		*start = NULL;
	}

	if (*start != NULL)// если в очереди больше одного элемента
	{
		if ((*start)->next != (*end))// если больше 2 элементов в очереди
		{
			hlpy = *start;// сохраняем указатель на начало
			(*start) = (*start)->next;// передвигаем указатель на начало
		}
		else// если 2 элемента в очереди
		{
			hlpy = *start;// сохраняем указатель на начало
			*start = *end;// начало передвигается и теперь оно там же, где конец, у нас 1 элемент
		}
	}

	free(hlpy);// освобождаем память из под элемента очереди
	if (*start != NULL) {
		print_ocher1(start, end);
	}
	
}

struct ocher2* delete_el_ochered_begin(struct ocher2** start2, struct ocher2** end2, struct ocher2** uk)// функция удаления элемента из начала второй очереди
{
	struct ocher2* hlpy = NULL;
	if (*start2 == NULL && *end2 == NULL)// если очередь пуста
		printf("Очередь пуста ,невозможно удалить элемент \n");
	if (*start2 != NULL && (*start2) == (*end2))// если у нас только один элемент
	{
		hlpy = *start2;// помещаем указатель на этот элемент в вспомогательный указатель
		*end2 = NULL;// обнуляем указатели
		*start2 = NULL;
	}

	if (*start2 != NULL)// если в очереди больше одного элемента
	{
		if ((*start2)->next != (*end2))// если больше 2 элементов в очереди
		{
			hlpy = *start2;// сохраняем указатель на начало
			(*start2) = (*start2)->next;// передвигаем указатель на начало
		}
		else// если 2 элемента в очереди
		{
			hlpy = *start2;// сохраняем указатель на начало
			*start2 = *end2;// начало передвигается и теперь оно там же, где конец, у нас 1 элемент
		}
	}

	free(hlpy);// освобождаем память из под элемента очереди
	if (*start2 != NULL) {
		print_ocher(start2, end2);
	}
	*uk = *start2;
	return *uk;
}

void check_el_start(struct ocher2** start2) 
{
	if (*start2 == NULL) {
		printf("Очередь пуста!\n");
	}
	else {
		printf("Элемент в начале очереди\n");
		printf("%d", (*start2)->dataint);
	}
}

void check_ocher(struct ocher2** start2, struct ocher2** end2) 
{
	if (*start2 == NULL) {
		printf("Очередь пуста!\n");
	}
	else {
		printf("В очереди есть элементы\n");
	}
}


void check_ocher1(struct ocher** start, struct ocher** end) {
	if (*start == NULL) {
		printf("Очередь пуста!\n");
	}
	else {
		printf("В очереди есть элементы\n");
	}
}

void add_el_ocher1_end(struct ocher** start, struct ocher** end, struct ocher2** start2, struct ocher2** end2, int numfo, int* save, int* o, int* flag)
{
	struct ocher* tmp;
	if (*end != NULL)//если в конце что-то есть
	{
		tmp = (struct ocher*)malloc(sizeof(struct ocher));// выделяем память под новый элемент
		if (tmp == NULL)// проверяем, выделилась ли память
		{
			printf("Ошибка, невозможно выделить память\n");
			exit(1);
		}
		(*end)->next = tmp;// добавляем этот элемент в конец

		tmp = menu_ocher2(tmp, start2, end2, save, flag);//вызываем меню второй очереди

		*end = tmp;// передвигаем указатель на конец
		print_ocher1(start, end);//печатаем очередь
	}
	if (*end == NULL)//если нет элементов в очереди
	{
		tmp = (struct ocher*)malloc(sizeof(struct ocher));// выделяем память под новый элемент
		if (tmp == NULL)
		{
			printf("Ошибка, невозможно выделить память\n");
			exit(1);
		}
		tmp->next = NULL;// указатель на следующий элемент обнуляем
		tmp = menu_ocher2(tmp, start2, end2, save, flag);// вызов меню второй очереди
		*start = tmp;// обновляем указатель на старт
		*end = tmp;//обновляем указатель на конец
		print_ocher1(start, end);// печатаем очередь
	}
}

struct ocher2* add_el_ocher2_end(struct ocher2** start2, struct ocher2** end2, struct ocher2** uk)//функция добавления элемента в конец второй очереди
{
	struct ocher2* tmp = NULL;// вспомогательный указатель
	int cymbol;//вспомогательная переменная

	if (*end2 != NULL)
	{
		struct ocher2* newl, * vsp;
		newl = (struct ocher2*)malloc(sizeof(struct ocher2));
		if (newl==NULL) {
			printf("Ошибка, невозможно выделить память\n");
			exit(1);
		}
		vsp = (*end2)->next;
		printf("Введите символ , который хотите добавить в конец\n");
		scanf_s("%d", &cymbol);
		(*end2)->next = newl;
		newl->next = vsp;
		newl->dataint = cymbol;
		system("cls");
		print_ocher(start2, end2);
	}

	if (*end2 == NULL)// если вторая очередь пуста
	{
		tmp = (struct ocher2*)malloc(sizeof(struct ocher2));//выделяем память под новый элемент
		if (tmp == NULL)//проверка, выделилась ли память
		{
			printf("Ошибка, невозможно выделить память\n");
			exit(1);
		}
		tmp->next = NULL;
		printf("Введите символ , который хотите добавить в конец\n");
		scanf_s(" %d", &cymbol);//вводим новый символ
		tmp->dataint = cymbol;//заносим символ
		*start2 = tmp;//обновляем старт
		*end2 = tmp;//обноввляем конец
		*uk = *start2;
		system("cls");
		print_ocher(start2,end2);
	}
	return *uk;//возвращаем указатель на вторую очередь
}

void clear_ochered1(struct ocher** start, struct ocher** end)// функция очистки очереди
{
	struct ocher* ry = NULL;// содаем вспомогательный указатель
	struct ocher2* tt = NULL;// содаем вспомогательный указатель
	if (*start != NULL && *end != NULL)// если очередь не пуста
	{
		while (*start != *end)// пока мы не дощли до последнего элемента очереди
		{
			ry = *start;// помещаем указатель на старт в новый указатель на элемент очереди
			tt = (*start)->data;// помещаем указатель на вторую очередь в новый указатель на элемент второй очереди
			while (tt != NULL)// пока не дошли до последнего элемента
			{
				(*start)->data = (*start)->data->next;// передвигаем указатель
				free(tt);// освобождаем память из под элемента второй очереди
				tt = (*start)->data;// присваиваем указатель на следующий элемент второй очереди
			}
			*start = (*start)->next;// передвигаем указатель на старт очереди
			free(ry);// освобождаем память из под элемента очереди

		}
		tt = (*start)->data;// присваивает указатель на последний элемент второй очереди
		while (tt != NULL)// освобождаем вторую очередь 
		{
			(*start)->data = (*start)->data->next;
			free(tt);
			tt = (*start)->data;
		}
		free(*start);// освобождаем память из под последнего элемента очереди
		*start = NULL;
		*end = NULL;

		printf("Очередь очищена\n");
	}
	else
		printf("Очередь  пуста\n");
}

struct ocher2* clear_ochered(struct ocher2** start2, struct ocher2** end2, struct ocher2* uk)// функция очистки очереди
{
	ocher2* ry;// содаем вспомогательный указатель
	if (*start2 != NULL && *end2 != NULL)// если он не пуст
	{
		while (*start2 != *end2)// пока не дойдём до последнего элемента второй очереди
		{
			ry = *start2;//помещаем указатель на старт в новый указатель на вторую очередь
			*start2 = (*start2)->next;// передвигаем указатель на старт
			free(ry);// освобождаем память
		}
		free(*start2);// освобождаем панять из под последнего элемента 
		*start2 = NULL;
		*end2 = NULL;

		printf("Очередь очищена\n");
	}
	else
		printf("Очередь  пуста\n");
	uk = *start2;//в указател  на вторую очередь помещаем указатель на старт нашей второй очереди
	return uk;
}

void end_work_ochered(struct ocher** start, struct ocher** end)// функция окончания работы с очередью
{
	if (*start != NULL && *end != NULL) {// если очередь не пуста
		clear_ochered1(start, end);//вызов функции очистки очереди
	}
	
}
void start_work_ochered2(struct ocher2** start2, struct ocher2** end2)// функция начала работы с очередью
{
	*start2 = NULL;
	*end2 = NULL;
	printf("Работа с очередью начата\n");
}

void start_work_ochered(struct ocher** start, struct ocher** end)// функция начала работы с очередью
{
	*start = NULL;
	*end = NULL;
	printf("Работа с очередью начата\n");
}

struct ocher* menu_ocher2(struct ocher* uk2, struct ocher2** start2, struct ocher2** end2, int* save, int* flag) {
	int o = 0;
	int numfo = 0;
	bool c = true;
	int f=0;
	struct ocher2* uk = NULL;
	bool work2 = false;
	while (numfo!=10) {
		printf("\nВыберите действие с очередью :\n");
		printf("1.Начать работу с очередью\n");
		printf("2.Сделать очередь пустой \n");
		printf("3.Проверить пуста ли очередь\n");
		printf("4.Показать значение элемента в начале очереди\n");
		printf("5.Удалить начало очереди\n");
		printf("6.Взять элемент из начала очереди\n");
		printf("7.Изменить значение элемента в начале очереди\n");
		printf("8.Добавить элемент в конец очереди\n");
		printf("9.Распечатать очередь\n");
		printf("10.Закончить работу с очередью\n");
		scanf_s("%d", &numfo);
		switch (numfo) {
		case 1: {
			system("cls");
			if (work2 == false) {
				f = 1;
				
				if (*flag == 1)//если мы зашли изменить элемент очереди
				{
					*start2 = uk2->data;//передаем в указатель на старт указатель второй очереди, который хотим изменить
					 uk= *start2;// в наш указател на вторую очередь, сохраняем указатель на старт
					while (*start2 != NULL)// ищем конец нашего дека
					{
						*end2 = *start2;
						*start2 = (*start2)->next;
						// параллельно считаем количество элементов текущей очереди
					}
					*start2 = uk2->data;// в страрт снова помещаем указатель на нашу очередь
					uk = *start2;// в наш указател на очередь, сохраняем указатель на старт
					printf("Работа с очередью начата\n");
				}
				else {// если мы просто добаляем новый элемент в очередь, то начинаем работу с новой очередью
					start_work_ochered2(start2, end2);
					o2 = 0;
				}
				work2 = true;
			}
			else {
				printf("Вы уже начали работу\n");
			}
			break;
		}
		case 2: {
			system("cls");
			if (work2 == true) {
				uk = clear_ochered(start2, end2, uk);
				o2 = 0;
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		case 3: {
			system("cls");
			if (work2 == true) {
				check_ocher(start2, end2);
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		case 4: {
			system("cls");
			if (work2 == true) {
				check_el_start(start2);
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		case 5: {
			system("cls");
			if (work2 == true) {
				uk = delete_el_ochered_begin(start2, end2,&uk);
				if (o2 > 0) {
					o2--;
				}
				
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		case 6: {
			system("cls");
			if (work2 == true) {
				uk = take_el_from_begin(uk, start2, end2, save);
				if (o2 > 0) {
					o2--;
				}
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		case 7: {
			system("cls");
			if (work2 == true) {
				uk = change_el_second_ochered(uk,start2,end2);
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		case 8: {
			system("cls");
			if (work2 == true) {
				if (o2 < 5) {
					uk = add_el_ocher2_end(start2, end2, &uk);
					*start2 = uk;
					o2++;
				}
				else {
					printf("Очередь переполнена, вы не можете добавить элемент\n");
				}
				
				break;
			}
			else {
				printf("Вы еще не начали работу\n");
				break;
			}
			
		}
		case 9: {
			system("cls");
			if (work2 == true) {
				print_ocher(start2, end2);
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		case 10: {
			system("cls");
			if (work2 == true) {
				
			}
			else {
				printf("Вы еще не начали работу\n");
			}
			break;
		}
		default:// если введено некоретное значение при выборе пункта меню
		{
			system("cls");
			printf("Вы ввели некорректное значение, попробуйте ещё раз\n");
			break;
		}
		}
	}
	if (f == 0 && *flag == 1)
	{
		*start2 = NULL;// обнуляем наш дек для повторного использования
		*end2 = NULL;
	}
	else// в другом случае
	{
		uk2->data = uk;// сохраняем указатель на изменённый или только добавленную очередь
		uk2->next = NULL;// этот элемент будет последним в очереди, поэтому указатель на следующий элемент NULL
		*start2 = NULL;// обнуляем нашу очередь для повторного использования
		*end2 = NULL;
	}
	return uk2;
}



int main() {
	setlocale(LC_ALL,"RUS");
	bool work = false;
	struct ocher* start = NULL;//указатель на начало первой очереди
	struct ocher* end = NULL;//указатель на конец первой очереди
	struct ocher* uk2 = NULL;//вспомогательный указатель 
	struct ocher2* start2= NULL;//указатель на начало второй очереди
	struct ocher2* end2 = NULL;//указатель на конец второй очереди
	struct ocher2* uk = NULL;//вспомогательный указатель второй очереди
	int numfo=0;//переменная для выбора пункта меню
	int o = 0;//переменная максимума очереди
	int save;//переменная для сохранения элемента
	struct ocher save2;//переменная для сохранения переменной первой очереди
	int flag = 0;// вспомогательный флаг, чтобы понимать, что мы зашли изменить элемент очереди
	
	while (1) {
		
		while (numfo!=11) {
			//system("cls");
			printf("\nВыберите действие с очередью :\n");
			printf("1.Начать работу с очередью\n");
			printf("2.Сделать очередь пустой \n");
			printf("3.Проверить пуста ли очередь\n");
			printf("4.Показать значение элемента в начале очереди\n");
			printf("5.Удалить начало очереди\n");
			printf("6.Взять элемент из начала очереди\n");
			printf("7.Изменить значение элемента в начале очереди\n");
			printf("8.Добавить элемент в конец очереди\n");
			printf("9.Распечатать очередь\n");
			printf("10 Завершить работу с очередью\n");
			printf("11 Выйти из программы\n");
			scanf_s("%d", &numfo);
			
			switch (numfo) {
			case 1: {
				system("cls");
				if (work == false) {
					start_work_ochered(&start, &end);
					work = true;
				}
				else {
					printf("Вы уже начали работу\n");
				}
				break;
			}
			case 2: {
				system("cls");
				if (work == true) {
					clear_ochered1(&start, &end);
					o = 0;
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 3: {
				system("cls");
				if (work == true) {
					check_ocher1(&start, &end);
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 4: {
				system("cls");
				if (work == true) {
					show_el_ocher1(&start,&end);
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 5: {
				system("cls");
				if (work == true) {
					delete_el_ocher1_begin(&start, &end);
					if (o > 0)
						o--;
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 6: {
				system("cls");
				if (work == true) {
					take_el_ocher1_begin(&start, &end, &save2);// вызов функции взятия элемента в начале очереди
					if (o > 0)// если счётчик больше нуля, т е в очереди что-то было взято
						o--;
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 7: {
				system("cls");
				if (work == true) {
					change_el_ocher1_begin(&start, &end, &start2, &end2, &save,&flag);
					flag = 0;
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 8: {
				system("cls");
				if (work == true) {
					if (o < 5) {
						add_el_ocher1_end(&start, &end, &start2, &end2, numfo, &save, &o, &flag);
						o++;
					}
					else {
						printf("Очередь переполнена, вы не можете добавить элемент\n");
					}
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 9: {
				system("cls");
				if (work == true) {
					print_ocher1(&start, &end);
				}
				else {
					printf("Вы еще не начали работу\n");
				}
				break;
			}
			case 10:
			{     system("cls");
			if (work == true)
			{
				end_work_ochered(&start, &end);// вызов функции окончания работы с очередью
				work = false;// меняем флаг
				o = 0;// обнуляем счётчик элементов
			}
			else// если ещё не начали работу
				printf("Вы еще не начали работу с очередью\n");
			break;
			}
			case 11: {
				//system("cls");
				exit(1);
				break;

			}
			default:// если введено некоретное значение при выборе пункта меню
			{
				system("cls");
				printf("Вы ввели некорректное значение, попробуйте ещё раз\n");
				break;
			}
			}
		}
	}
}