#bin.sh

echo '<svg width="100" height="100">
    <g id="sol">
        <rect x="0" y="80" width="100" height="20" fill="green" cx="110"/>
    </g>
    <g id="ciel" cx="110">
        <rect x="0" y="0" width="100" height="80" fill="blue"/>
        <g id="soleil">
            <circle cx="0" cy="0" r="20" stroke="yellow" fill="orange" stroke-width="5">
                <driven target="cx" by="sun_x"/>
                <driven target="cy" by="sun_y"/>
            </circle>
        </g>
    </g>
    <g id="maison">
        <rect x="0" y="0" width="30" height="23" fill="gray">
            <driven target="x" by="house_x"/>
            <driven target="y" by="house_y"/>
        </rect>
        <polyline points="60 65 75 55 90 65" stroke="black" fill="red" stroke-width="1"/>
    </g>
</svg>
' > toto.svg
make
./main 2> error.txt
