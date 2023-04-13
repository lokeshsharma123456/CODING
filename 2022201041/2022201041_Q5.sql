
select * 
from
(SELECT Essn  
    FROM DEPENDENT  WHERE sex = 'F' 
      group by Essn having count(sex) >1) AS A 
       INNER JOIN
        DEPARTMENT AS D 
         on D.Mgr_ssn=A.Essn 
    inner join
        DEPT_LOCATIONS AS L 
        on L.Dnumber=D.Dnumber 
        Group by D.Dnumber , D.Essn;
