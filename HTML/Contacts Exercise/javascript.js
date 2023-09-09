let i = 0;

function add() {
    const lname = document.getElementById('lname')
    const fname = document.getElementById('fname')
    const email = document.getElementById('email')
    const contact = document.getElementById('contact')

    if (lname.value === '' && fname.value === '' && email.value === '' && contact.value === '') {
        alert('Fill Inputs!')
        return
    }

    const table = document.getElementById('main_table')

    const row = document.createElement('tr')
    row.id = 'row'+i
    const c1 = document.createElement('td')
    const c2 = document.createElement('td')
    const c3 = document.createElement('td')
    const c4 = document.createElement('td')

    c1.textContent = lname.value + ', ' + fname.value
    c2.textContent = email.value
    c3.textContent = contact.value

    const del_but = document.createElement('button')
    del_but.textContent = 'delete'
    del_but.setAttribute( "onclick", "del_row("+i+")")

    c4.appendChild(del_but)

    row.appendChild(c1)
    row.appendChild(c2)
    row.appendChild(c3)
    row.appendChild(c4)

    table.appendChild(row)
    i++
}

function del_row( value ) {
    const row = document.getElementById('row'+value)
    row.remove()
}