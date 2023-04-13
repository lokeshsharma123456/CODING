SELECT EMP.Fname ,EMP.Minit, EMP.Lname , EMP.Super_ssn , Dept.Dnumber , COUNT(EMP.Ssn) as ord
 from EMPLOYEE as EMP
inner join 
DEPARTMENT as Dept
on Dept.Mgr_ssn=EMP.Super_ssn 
GROUP BY  
EMP.Fname ,EMP.Minit, EMP.Lname , EMP.Super_ssn , Dept.Dnumber
order by ord;
