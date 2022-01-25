program database;
type TRec = record
       a: integer;
       b: string;
     end;
const MAX_SIZE = 100;
      CMD_NONE = 0;
      CMD_EXIT = -1;
      CMD_SHOW = 1;
      CMD_ADD = 2;
      CMD_DELETE = 3;
var cmd: integer;
    data: array[1..MAX_SIZE] of TRec;
    
{-----------------------------------
  READ DATABASE - чтение данных из файла
-----------------------------------}
procedure ReadDatabase;
begin
end;

{-----------------------------------
  SAVE DATABASE - запись данных в файл
-----------------------------------}
procedure SaveDatabase;
begin
end;

{-----------------------------------
  МЕНЮ
-----------------------------------}
function Menu: integer;
var opt: integer;
begin
  ReadDatabase;
  repeat
    writeln;
    writeln('Выберите действие:');
    writeln(' 1 - просмотр данных');
    writeln(' 2 - добавление записи');
    writeln(' 3 - удаление записи');
    writeln(' 4 - выход');
    write  ('> ');
    readln(opt);
    case opt of
      1: opt := CMD_SHOW;
      2: opt := CMD_ADD;
      3: opt := CMD_DELETE;
      4: opt := CMD_EXIT;
      else opt := CMD_NONE;
    end;
  until opt <> CMD_NONE;
  Menu := opt;
end;

{-----------------------------------
  SHOW DATA - показать все записи
-----------------------------------}
procedure ShowData;
begin
end;

{-----------------------------------
  ADD RECORD - добавить запись
-----------------------------------}
procedure AddRecord;
var newRec: TRec;
begin
  writeln('Введите данные новой записи:');
  write  ('  a > '); readln(newRec.a);
  write  ('  b > '); readln(newRec.b);
  { здесь добавляем запись newRec в массив структур }
  SaveDatabase;
  writeln('Запись добавлена.');
end;

{-----------------------------------
  DELETE RECORD - удалить запись
-----------------------------------}
procedure DeleteRecord;
var no: integer;
begin
  writeln('Введите номер записи для удаления: ');
  readln(no);
  { здесь удаляем запись из массива структур }
  SaveDatabase;
  writeln('Запись ', no, ' удалена.');
end;

{-----------------------------------
  Основная программа
-----------------------------------}
begin
  cmd := CMD_NONE;
  while cmd <> CMD_EXIT do begin
    cmd := Menu;
    case cmd of
      CMD_SHOW:   ShowData;
      CMD_ADD:    AddRecord;
      CMD_DELETE: DeleteRecord;
    end;
  end;
  writeln('Работа закончена.');
end.
