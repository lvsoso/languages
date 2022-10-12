package md

import (
	"fmt"
	"io/ioutil"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/assert"
)

// var realPath = "/home/lv/lvsoso/languages/go/markdown/md"

var virPath = "/doc"
var virPath2 = "/doc/readme"

var testFIles = []string{
	"/doc/ch1/ch1.md",
	"/doc/changelog.md",
	"/doc/readme/readme.md",
	"/doc/readme.md",
	"/doc/README.md"}

func Test_F(t *testing.T) {
	for idx := range testFIles {
		p := filepath.Join(virPath, testFIles[idx])
		println(p)
	}

}

func Test_ReplaceLink(t *testing.T) {
	f := "../test_files/doc/README.md"
	data, err := ioutil.ReadFile(f)
	assert.Nil(t, err)

	fmt.Println(MdHandle(string(data), virPath))
}

func Test_ReplaceLink2(t *testing.T) {
	f := "../test_files/doc/readme/readme.md"
	data, err := ioutil.ReadFile(f)
	assert.Nil(t, err)

	fmt.Println(MdHandle(string(data), virPath2))
}
