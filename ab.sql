set serveroutput on 
DECLARE
    CURSOR cur(v_accno ACCOUNT.accno%TYPE, vmon varchar) IS
    SELECT T.accno, T.TR_TYPE, T.AMOUNT, T.tr_date, A.BALANCE FROM account A join  transaction T on T.accno=A.accno WHERE T.accno = v_accno and to_char(T.tr_date,mon)=vmon;

    total_debit NUMBER:=0;
    total_credit NUMBER :=0;
    total_balance NUMBER:=0;

    t_v_accno TRANSACTION.ACCNO%TYPE;

BEGIN
    FOR i IN cur(&t_v_accno) 
    LOOP
        IF i.TR_TYPE = 'Cr' THEN
            total_credit := total_credit + i.AMOUNT;
        ELSIF i.TR_TYPE = 'Db' THEN
            total_debit := total_debit + i.AMOUNT;
        END IF;

    END LOOP;

    

   -- SELECT A.BALANCE INTO total_balance FROM account A, transaction T where A.accno=T.accno and T.accno=t_v_accno;
   total_balance := 400000 + total_credit - total_debit;


    DBMS_OUTPUT.PUT_LINE('ACC NO : ' || t_v_accno);
    DBMS_OUTPUT.PUT_LINE('Total Debit : ' || total_debit);
    DBMS_OUTPUT.PUT_LINE('Total Credit : ' || total_credit);
    DBMS_OUTPUT.PUT_LINE('Total Balance : ' || total_balance);
END;
/