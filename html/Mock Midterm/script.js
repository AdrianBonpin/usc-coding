function activateTab(tsend) {
    var tab1 = document.getElementById("tab1");
    var tab2 = document.getElementById("tab2");
    var tab3 = document.getElementById("tab3");
    var tab4 = document.getElementById("tab4");
    if(tsend === 't1'){
      tab1.className = "tabButton active";
      tab2.className = "tabButton";
      tab3.className = "tabButton";
      tab4.className = "tabButton";
    }else if(tsend === 't2'){
      tab1.className="tabButton";
      tab2.className="tabButton active";
      tab3.className="tabButton";
      tab4.className = "tabButton";
    }else if(tsend === 't3'){
      tab1.className="tabButton";
      tab2.className="tabButton";
      tab3.className="tabButton active";
      tab4.className = "tabButton";
    }else{
        tab1.className="tabButton";
        tab2.className="tabButton";
        tab3.className="tabButton";
        tab4.className = "tabButton active";
      }
  }