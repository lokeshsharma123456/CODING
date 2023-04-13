SELECT EMP.Fname ,EMP.Minit, EMP.Lname,Dept.Mgr_Ssn ,Dept.Dnumber ,Dept.Dname 
  FROM EMPLOYEE as EMP
     inner join
       WORKS_ON as Works 
       on Works.Essn=EMP.Ssn
     inner join
      DEPARTMENT as Dept
      on Works.Essn=Dept.Mgr_ssn 
	WHERE  
	Works.Hours < 40.0 ;

