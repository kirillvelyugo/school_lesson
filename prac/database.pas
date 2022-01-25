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
  READ DATABASE - ������ ������ �� �����
-----------------------------------}
procedure ReadDatabase;
begin
end;

{-----------------------------------
  SAVE DATABASE - ������ ������ � ����
-----------------------------------}
procedure SaveDatabase;
begin
end;

{-----------------------------------
  ����
-----------------------------------}
function Menu: integer;
var opt: integer;
begin
  ReadDatabase;
  repeat
    writeln;
    writeln('�������� ��������:');
    writeln(' 1 - �������� ������');
    writeln(' 2 - ���������� ������');
    writeln(' 3 - �������� ������');
    writeln(' 4 - �����');
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
  SHOW DATA - �������� ��� ������
-----------------------------------}
procedure ShowData;
begin
end;

{-----------------------------------
  ADD RECORD - �������� ������
-----------------------------------}
procedure AddRecord;
var newRec: TRec;
begin
  writeln('������� ������ ����� ������:');
  write  ('  a > '); readln(newRec.a);
  write  ('  b > '); readln(newRec.b);
  { ����� ��������� ������ newRec � ������ �������� }
  SaveDatabase;
  writeln('������ ���������.');
end;

{-----------------------------------
  DELETE RECORD - ������� ������
-----------------------------------}
procedure DeleteRecord;
var no: integer;
begin
  writeln('������� ����� ������ ��� ��������: ');
  readln(no);
  { ����� ������� ������ �� ������� �������� }
  SaveDatabase;
  writeln('������ ', no, ' �������.');
end;

{-----------------------------------
  �������� ���������
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
  writeln('������ ���������.');
end.
